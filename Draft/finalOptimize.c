#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIMILARITY_THRESHOLD 0.95
#define MAX_PROGRAMS 300
#define MAX_LENGTH 100000
#define NHASH  3001
#define MULT  37

int min(int x, int y) {
    return x < y ? x : y;
}

int error(char *s) {
    fprintf(stderr, "%s\n", s); 
    exit(-1); 
}

typedef struct list {
    char val[20];
    char *keyInfo;
    int appearance;
    struct list *next;
} list;

list *hh[NHASH];
list *ff[NHASH];

unsigned int hash(char *str) {
    unsigned int h = 0;
    char *p;
    for (p = str; *p != '\0'; p++)
        h = MULT * h + *p;
    return h % NHASH;
}

int hSearch(char s[]) {
    unsigned int x = hash(s);
    list *p = hh[x];
    while (p != NULL) {
        if (strcmp(p->val, s) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}

int fSearch(char s[]) {
    unsigned int x = hash(s);
    list *p = ff[x];
    while (p != NULL) {
        if (strcmp(p->val, s) == 0)
            return 1;
        p = p->next;
    }
    return 0;
}

list *LLLhSearch(char s[]) {
    unsigned int x = hash(s);
    list *p = ff[x];
    while (p != NULL) {
        if (strcmp(p->val, s) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

int editdistDP(char *str1, char *str2, int **Dp) {
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                Dp[i][j] = j;
            else if (j == 0)
                Dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                Dp[i][j] = Dp[i-1][j-1];
            else
                Dp[i][j] = 1 + min(Dp[i][j-1], Dp[i-1][j], Dp[i-1][j-1]);
        }
    }
    return Dp[len1][len2];
}

void processSingleProgram_keyInfo(char *program, char *target, int **Dp) {
    for (int i = 0; i < NHASH; i++)
        ff[i] = NULL;

    int i = 0, bracket = 0;
    int j = 0;

    while (program[i] != '\0') {
        int sig = 0;
        while (program[i] != '{' && bracket == 0) {
            if (program[i] == '(') sig = 1;
            if (sig == 0) target[j++] = program[i++];
            else i++;
        }
        target[j++] = program[i++];
        if (program[i-1] == '{') bracket++;
        while (bracket != 0) {
            if (program[i] == '{') bracket++;
            if (program[i] == '}') bracket--;
            if (bracket != 0) target[j++] = program[i++];
        }
        target[j++] = program[i++];
        bracket = 0;
    }
    target[j] = '\0';
}

void processPrograms(const char *filename, int **Dp) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LENGTH];
    char c;
    int id;

    while (fscanf(file, "%d", &id) != EOF) {
        programs[programCount].id = id;

        int j = 0;
        while (fscanf(file, "%c", &c) != EOF) {
            if (c == '\f') break;
            else {
                if (c != '\n' && c != '\r' && c != '\t') buffer[j++] = c;
            }
        }
        buffer[j] = '\0';

        processSingleProgram_keyInfo(buffer, programs[programCount].keyInfo, Dp);
        programCount++;
    }
    fclose(file);
}

double calculateSimilarity(char *keyInfo1, char *keyInfo2, int **Dp) {
    int editDistance = editdistDP(keyInfo1, keyInfo2, Dp);
    int maxLength = (strlen(keyInfo1) > strlen(keyInfo2)) ? strlen(keyInfo1) : strlen(keyInfo2);
    return 1 - (double)editDistance / maxLength;
}

void findSimilarPrograms(int **Dp) {
    int clustered[MAX_PROGRAMS] = {0};  
    for (int i = 0; i < programCount; i++) {
        if (clustered[i]) continue;
        clustered[i] = 1;
        int sig = 0;
        for (int j = 0; j < programCount; j++) {
            if (j != i && calculateSimilarity(programs[i].keyInfo, programs[j].keyInfo, Dp) > SIMILARITY_THRESHOLD) {
                if (!sig) {
                    printf("%d", programs[i].id);
                    sig = 1;
                }
                printf(" %d", programs[j].id);
                clustered[j] = 1;
            }
        }
        if (sig) printf("\n");
    }
}

int main() {
    int **Dp;
    Dp = (int **)malloc(MAX_LENGTH * sizeof(int *));
    for (int i = 0; i < MAX_LENGTH; i++)
        Dp[i] = (int *)malloc(MAX_LENGTH * sizeof(int));

    loadKeepwords("keepwords.txt");

    processPrograms("codes.txt", Dp);

    findSimilarPrograms(Dp);

    // 释放动态分配的内存
    for (int i = 0; i < MAX_LENGTH; i++)
        free(Dp[i]);
    free(Dp);

    return 0;
}

