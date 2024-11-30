#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FUNC_NAME_LEN 100
#define MAX_KEYWORDS 256

// 定义用户函数节点结构
typedef struct FuncNode {
    char name[MAX_FUNC_NAME_LEN]; // 函数名
    char *infoStream;             // 函数的关键信息流
    struct FuncNode *next;        // 链表中的下一个节点
} FuncNode;

// 定义函数链表结构
typedef struct {
    FuncNode *head;               // 链表头指针
} FuncList;

// 全局变量
FuncList userFuncs;               // 用户定义函数的链表
char *keywords[MAX_KEYWORDS];     // 关键字和标准库函数名数组
int keywordCount = 0;             // 关键字计数

// 函数声明
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

    // 读取关键字和标准库函数名
    readKeywords(argv[2]);

    // 生成源文件的关键信息流
    char *mainStream = generateInfoStream(argv[1]);

    // 合并主函数及其直接调用的用户定义函数的关键信息流
    char *finalStream = mergeMainAndCalledFuncs(mainStream);

    // 输出最终的关键信息流
    printf("%s\n", finalStream);

    // 清理内存
    free(mainStream);
    free(finalStream);

    return 0;
}

// 从文件中读取关键字和标准库函数名
void readKeywords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open keepwords file");
        exit(1);
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // 去除换行符
        keywords[keywordCount] = strdup(buffer);
        keywordCount++;
    }

    fclose(file);
}

// 判断一个单词是否为关键字或标准库函数
int isKeywordOrStdFunc(const char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// 将用户定义的函数及其关键信息流添加到链表中
void addUserFunc(const char *funcName, const char *infoStream) {
    FuncNode *node = (FuncNode *)malloc(sizeof(FuncNode));
    strncpy(node->name, funcName, MAX_FUNC_NAME_LEN);
    node->infoStream = strdup(infoStream);
    node->next = userFuncs.head;
    userFuncs.head = node;
}

// 生成源文件的关键信息流
char *generateInfoStream(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open source file");
        exit(1);
    }

    // 读取整个文件内容
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *code = (char *)malloc(fileSize + 1);
    fread(code, 1, fileSize, file);
    code[fileSize] = '\0';

    fclose(file);

    // 提取用户定义的函数及其信息流
    char *infoStream = extractFunctions(code);

    free(code);
    return infoStream;
}

// 提取用户定义的函数及其信息流
char *extractFunctions(const char *code) {
    const char *p = code;
    char funcName[MAX_FUNC_NAME_LEN];
    char buffer[4096];
    char *infoStream = (char *)malloc(4096);
    infoStream[0] = '\0';

    while (*p) {
        // 跳过空白字符
        while (*p && isspace(*p)) p++;

        // 检查是否是函数定义
        const char *start = p;
        while (*p && (isalnum(*p) || *p == '_')) p++;

        if (*p == '(') {
            int len = p - start;
            strncpy(funcName, start, len);
            funcName[len] = '\0';

            if (!isKeywordOrStdFunc(funcName)) {
                // 这是一个用户定义函数
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

                    // 提取函数体
                    len = bodyEnd - bodyStart + 1;
                    strncpy(buffer, bodyStart, len);
                    buffer[len] = '\0';

                    // 删除空白字符并替换用户定义的函数调用
                    char *filteredBody = (char *)malloc(len + 1);
                    char *q = filteredBody;
                    for (const char *r = buffer; *r; r++) {
                        if (!isspace(*r)) {
                            if (isalnum(*r) || *r == '_') {
                                // 收集一个单词
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

                    // 将用户定义函数及其信息流添加到链表中
                    addUserFunc(funcName, filteredBody);
                    free(filteredBody);
                }
            }
        }

        // 跳到下一行
        while (*p && *p != '\n') p++;
    }

    // 提取主函数的信息流
    char *mainStream = getInfoStream("main");
    strcpy(infoStream, mainStream);
    free(mainStream);

    return infoStream;
}

// 获取指定函数的关键信息流
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

// 合并主函数及其直接调用的用户定义函数的信息流
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
