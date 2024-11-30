#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIMILARITY_THRESHOLD 0.95
#define MAX_PROGRAMS 300      // ����������
#define MAX_LENGTH 100000      // ÿ���������󳤶�
#define NHASH  3001
#define MULT  37
#define min(x,y)  ( x<y?x:y )
#define max2(a,b) ((a)>(b)?(a):(b))
int **Dp, MaxDP=5000;								//for dynamic programming
int min3(int a, int b, int c){
    int min = a < b ? a : b;
    return min < c ? min : c;
}
int error2(char *s){
    fprintf(stderr,"%s\n",s); 
    exit(-1); 
}
int initDP(){		
    int i;
    Dp = (int **)malloc(MaxDP*sizeof(int *));
    for(i=0; i<MaxDP; i++)
    Dp[i] = (int *)malloc(MaxDP*sizeof(int));
	return 0;	
}
int editdistDP(char *str1, char *str2) {//����༭����
    int i,j;
    int len1, len2;
    static int flag=0;
    (flag++) ? 1 : initDP(); 
    len1 = strlen(str1)+1; len2 = strlen(str2)+1;
    (max2(len1,len2)>=MaxDP) ? error2("DP memory error!") : len1;
    for (i=0; i<=len1; i++) {
        for (j=0; j<=len2; j++) {
            if (i==0)
                Dp[i][j] = j;
            else if (j==0)
                Dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                Dp[i][j] = Dp[i-1][j-1];
            else
                Dp[i][j] = 1 + min3(Dp[i][j-1], Dp[i-1][j], Dp[i-1][j-1]);
        }
    }
    return Dp[len1][len2];
}
//��ϣ����
unsigned int hash(char *str){
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}
int ind[30];//������

typedef struct list{
    char val[20];
    struct list *next;
}list;

list *hh[3500];
list * hSearch(char s[]){
    unsigned int x=hash(s);
    list *p=hh[x];
    while(p!=NULL){
        if(strcmp(p->val,s)==0)return p;
        else if(strcmp(p->val,s)>0)return NULL;
        p=p->next;
    }
    return NULL;
}
// �ṹ�嶨�壬���ڴ洢�����ż���ؼ���Ϣ��
typedef struct {
    int id;
    char keyInfo[MAX_LENGTH];//��������Ĺؼ���Ϣ��
} Program;

Program programs[MAX_PROGRAMS];   // �洢���г���
int programCount = 0;             // ��¼��������
char keepwords[MAX_PROGRAMS][MAX_LENGTH];  // �洢���йؼ��ֺͱ�׼�⺯����
int keepwordsCount = 0;           // ��¼�ؼ��ֺͱ�׼�⺯������

// ��ȡ keepwords.txt �ļ������عؼ��ֺͱ�׼�⺯����
void loadKeepwords(const char *filename) {
    FILE *file = fopen(filename, "r");
    while (fscanf(file, "%s", keepwords[keepwordsCount]) != EOF) {
        list *p=(list *)malloc(sizeof(list));
        unsigned int x=hash(keepwords[keepwordsCount]);
        strcpy(p->val,keepwords[keepwordsCount]);
        p->next=hh[x];
        hh[x]=p;
        keepwordsCount++;
    }
    fclose(file);
    //for(int i=0;i<keepwordsCount;i++)printf("%s\n",keepwords[i]);
}

// �ж�һ�����Ƿ�Ϊ�ؼ��ֻ��׼�⺯����(�˴������Ż�)
int isKeepword(char *word) {
    list *r=hSearch(word);
    if(r==NULL){
        free(r);
        return 0;
    }
    free(r);
    return 1;
}

// �����������ݣ����ɹؼ���Ϣ��(ÿ����ź��һ�γ���)
void processFunctionBody(char *body, char *keyInfo) {
    int i = 0, j = 0;
    while (body[i] != '\0') {
        // �����հ��ַ�
        if (body[i] == ' ' || body[i] == '\n' || body[i] == '\r' || body[i] == '\t') {
            i++;
            continue;
        }
        if(isalpha(body[i])||body[i]=='_'){
            char tmp[20];//��ʱ�ַ������ж��Ƿ�Ϊ�ؼ���
            int k=0;
            while (isalpha(body[i]) || body[i] == '_' || isdigit(body[i])){
                tmp[k++]=body[i++];
            }
            tmp[k]='\0';
            //printf("%s\n",tmp);
            if(isKeepword(tmp)){//����ǹؼ��֣�����
                strcat(keyInfo,tmp);
                j+=k;
            }else{//���ǹؼ��֣�����ͨ����������ΪFUNC
                strcat(keyInfo,"FUNC");
                j+=4;
            }
        }else{
            keyInfo[j++] = body[i++];
        }
        // �����ؼ��ֺͱ�׼�⺯����
    //     if (isKeepword(&body[i])) {
    //         while (body[i] != ' ' && body[i] != '\n' && body[i] != '\r' && body[i] != '\t' && body[i] != '\0') {
    //             keyInfo[j++] = body[i++];
    //         }
    //     // ���û����庯�����滻Ϊ "FUNC"
    //     } else if (isalpha(body[i]) || body[i] == '_') {
    //         while (isalpha(body[i]) || body[i] == '_' || isdigit(body[i])) {
    //             i++;
    //         }
    //         strcpy(&keyInfo[j], "FUNC");
    //         j += 4;
    //     } else {
    //         keyInfo[j++] = body[i++];
    //     }
    }
    keyInfo[j] = '\0';
}

// ��ȡ������벢����ÿ�������Ĺؼ���Ϣ��
void processPrograms(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LENGTH];
    char c;
    int id;
    while (fscanf(file, "%d", &id) != EOF) {
        //printf("$");
        programs[programCount].id = id;
        char keyInfo[MAX_LENGTH] = {'\0'};
        char body[MAX_LENGTH] = {'\0'};
        // ��ȡ����������ֱ����ҳ��
        int j=0;
        while (fscanf(file, "%c", &c) != EOF) {
            if(c=='\f')break;
            else body[j++]=c;
        }
        //printf("%s\n",body);
        processFunctionBody(body, keyInfo);
        strcpy(programs[programCount].keyInfo, keyInfo);
        programCount++;
    }
    fclose(file);
}

// ����������������ƶ�
double calculateSimilarity(char *keyInfo1, char *keyInfo2) {
    int editDistance = editdistDP(keyInfo1, keyInfo2);
    int maxLength = (strlen(keyInfo1) > strlen(keyInfo2)) ? strlen(keyInfo1) : strlen(keyInfo2);
    return 1.0 - (double)editDistance / maxLength;
}

// ���Ҳ�������Ƶĳ���
void findSimilarPrograms() {
    int clustered[MAX_PROGRAMS] = {0};  // ���ڱ���Ѵ���ĳ���
    for (int i = 0; i < programCount; i++) {
        if (clustered[i]) continue;
        //printf("%d", programs[i].id);
        clustered[i] = 1;
        // ����뵱ǰ�������Ƶ���������
        int sig=0;
        for (int j = i + 1; j < programCount; j++) {
            if (!clustered[j] && calculateSimilarity(programs[i].keyInfo, programs[j].keyInfo) > SIMILARITY_THRESHOLD) {
                if(!sig){
                    printf("%d", programs[i].id);
                    sig=1;
                }
                printf(" %d", programs[j].id);
                clustered[j] = 1;
            }
        }
        if(sig)printf("\n");
    }
}

int main() {
    // ���عؼ��ֺͱ�׼�⺯����
    loadKeepwords("keepwords.txt");
    // ��ȡ������벢����
    processPrograms("codes.txt");
    //printf("%s",programs[0].keyInfo);
    // ���Ҳ�������Ƶĳ���
    //printf("%d ",programCount);
    findSimilarPrograms();
    
    
    
    // loadKeepwords("keepwords.txt");
    // char s[]="int askldj lkji main main_int ^^^ malloc";
    // char key[100]={'\0'};
    // printf("%d\n",isKeepword(s));
    // processFunctionBody(s,key);
    // printf("%s",key);
    return 0;
}
