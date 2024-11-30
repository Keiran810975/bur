#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNC_NAME_LEN 100
#define MAX_KEYWORDS 256

// �����û������ڵ�ṹ
typedef struct FuncNode {
    char name[MAX_FUNC_NAME_LEN]; // ������
    char *infoStream;             // �����Ĺؼ���Ϣ��
    struct FuncNode *next;        // �����е���һ���ڵ�
} FuncNode;

// ���庯������ṹ
typedef struct {
    FuncNode *head;               // ����ͷָ��
} FuncList;

// ȫ�ֱ���
FuncList userFuncs;               // �û����庯��������
char *keywords[MAX_KEYWORDS];     // �ؼ��ֺͱ�׼�⺯��������
int keywordCount = 0;             // �ؼ��ּ���

// ��������
void readKeywords(const char *filename);
int isKeywordOrStdFunc(const char *word);
void addUserFunc(const char *funcName, const char *infoStream);
char *generateInfoStream(const char *filename);
char *extractFunctions(const char *code);
char *getInfoStream(const char *funcName);
char *mergeMainAndCalledFuncs(char *mainStream);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source.c> <keepwords.txt>\n", argv[0]);
        return 1;
    }

    // ��ȡ�ؼ��ֺͱ�׼�⺯����
    readKeywords(argv[2]);

    // ����Դ�ļ��Ĺؼ���Ϣ��
    char *mainStream = generateInfoStream(argv[1]);

    // �ϲ�����������ֱ�ӵ��õ��û����庯���Ĺؼ���Ϣ��
    char *finalStream = mergeMainAndCalledFuncs(mainStream);

    // ������յĹؼ���Ϣ��
    printf("%s\n", finalStream);

    // �����ڴ�
    free(mainStream);
    free(finalStream);

    return 0;
}

// ���ļ��ж�ȡ�ؼ��ֺͱ�׼�⺯����
void readKeywords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open keepwords file");
        exit(1);
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // ȥ�����з�
        keywords[keywordCount] = strdup(buffer);
        keywordCount++;
    }

    fclose(file);
}

// �ж�һ�������Ƿ�Ϊ�ؼ��ֻ��׼�⺯��
int isKeywordOrStdFunc(const char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// ���û�����ĺ�������ؼ���Ϣ����ӵ�������
void addUserFunc(const char *funcName, const char *infoStream) {
    FuncNode *node = (FuncNode *)malloc(sizeof(FuncNode));
    strncpy(node->name, funcName, MAX_FUNC_NAME_LEN);
    node->infoStream = strdup(infoStream);
    node->next = userFuncs.head;
    userFuncs.head = node;
}

// ����Դ�ļ��Ĺؼ���Ϣ��
char *generateInfoStream(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open source file");
        exit(1);
    }

    // ��ȡ�����ļ�����
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *code = (char *)malloc(fileSize + 1);
    fread(code, 1, fileSize, file);
    code[fileSize] = '\0';

    fclose(file);

    // ��ȡ�û�����ĺ���������Ϣ��
    char *infoStream = extractFunctions(code);

    free(code);
    return infoStream;
}

// ��ȡ�û�����ĺ���������Ϣ��
char *extractFunctions(const char *code) {
    const char *p = code;
    char funcName[MAX_FUNC_NAME_LEN];
    char buffer[4096];
    char *infoStream = (char *)malloc(4096);
    infoStream[0] = '\0';

    while (*p) {
        // �����հ��ַ�
        while (*p && isspace(*p)) p++;

        // ����Ƿ��Ǻ�������
        const char *start = p;
        while (*p && (isalnum(*p) || *p == '_')) p++;

        if (*p == '(') {
            int len = p - start;
            strncpy(funcName, start, len);
            funcName[len] = '\0';

            if (!isKeywordOrStdFunc(funcName)) {
                // ����һ���û����庯��
                while (*p && *p != '{') p++;
                if (*p == '{') {
                    const char *bodyStart = p;
                    int braces = 1;
                    while (*p && braces > 0) {
                        p++;
                        if (*p == '{') braces++;
                        else if (*p == '}') braces--;
                    }
                    const char *bodyEnd = p;

                    // ��ȡ������
                    len = bodyEnd - bodyStart + 1;
                    strncpy(buffer, bodyStart, len);
                    buffer[len] = '\0';

                    // ɾ���հ��ַ����滻�û�����ĺ�������
                    char *filteredBody = (char *)malloc(len + 1);
                    char *q = filteredBody;
                    for (const char *r = buffer; *r; r++) {
                        if (!isspace(*r)) {
                            if (isalnum(*r) || *r == '_') {
                                // �ռ�һ������
                                const char *wordStart = r;
                                while (isalnum(*r) || *r == '_') r++;
                                int wordLen = r - wordStart;
                                char word[MAX_FUNC_NAME_LEN];
                                strncpy(word, wordStart, wordLen);
                                word[wordLen] = '\0';

                                if (isKeywordOrStdFunc(word)) {
                                    strncpy(q, word, wordLen);
                                    q += wordLen;
                                } else {
                                    strcpy(q, "FUNC");
                                    q += 4;
                                }
                                r--;
                            } else {
                                *q++ = *r;
                            }
                        }
                    }
                    *q = '\0';

                    // ���û����庯��������Ϣ����ӵ�������
                    addUserFunc(funcName, filteredBody);
                    free(filteredBody);
                }
            }
        }

        // ������һ��
        while (*p && *p != '\n') p++;
    }

    // ��ȡ����������Ϣ��
    char *mainStream = getInfoStream("main");
    strcpy(infoStream, mainStream);
    free(mainStream);

    return infoStream;
}

// ��ȡָ�������Ĺؼ���Ϣ��
char *getInfoStream(const char *funcName) {
    FuncNode *node = userFuncs.head;
    while (node) {
        if (strcmp(node->name, funcName) == 0) {
            return strdup(node->infoStream);
        }
        node = node->next;
    }
    return strdup("");
}

// �ϲ�����������ֱ�ӵ��õ��û����庯������Ϣ��
char *mergeMainAndCalledFuncs(char *mainStream) {
    char *mergedStream = (char *)malloc(strlen(mainStream) + 1);
    strcpy(mergedStream, mainStream);

    FuncNode *node = userFuncs.head;
    while (node) {
        if (strstr(mainStream, node->name) && strcmp(node->name, "main") != 0) {
            char *funcStream = getInfoStream(node->name);
            mergedStream = (char *)realloc(mergedStream, strlen(mergedStream) + strlen(funcStream) + 1);
            strcat(mergedStream, funcStream);
            free(funcStream);
        }
        node = node->next;
    }

    return mergedStream;
}
