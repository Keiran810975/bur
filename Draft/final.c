#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIMILARITY_THRESHOLD 0.95
#define MAX_PROGRAMS 300      // 最大程序数量
#define MAX_LENGTH 100000      // 每个程序的最大长度
#define NHASH  3001
#define MULT  37//
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
int editdistDP(char *str1, char *str2) {//计算编辑距离
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
//哈希函数
unsigned int hash(char *str){
       unsigned int h=0;
       char *p;
       for(p=str; *p!='\0'; p++)
              h = MULT*h + *p;
       return h % NHASH;
}
int ind[30];//索引表

typedef struct list{
    char val[20];
    char *keyInfo;
    int appearance;//记录是否出现过
    struct list *next;
}list;

list *hh[3500];
list *ff[3500];//使用哈希去重
int hSearch(char s[]){
    unsigned int x=hash(s);
    list *p=hh[x];
    while(p!=NULL){
        if(strcmp(p->val,s)==0)return 1;
        //else if(strcmp(p->val,s)>0)return 0;
        p=p->next;
    }
    return 0;
}
int fSearch(char s[]){
    unsigned int x=hash(s);
    list *p=ff[x];
    while(p!=NULL){
        if(strcmp(p->val,s)==0)return 1;
        //else if(strcmp(p->val,s)>0)return 0;
        p=p->next;
    }
    return 0;
}
//返回结点的hsearch
list * LLLhSearch(char s[]){
    unsigned int x=hash(s);
    list *p=ff[x];
    while(p!=NULL){
        if(strcmp(p->val,s)==0)return p;
        //else if(strcmp(p->val,s)>0)return NULL;
        p=p->next;
    }
    return NULL;
}
// 结构体定义，用于存储程序编号及其关键信息流
typedef struct {
    int id;
    char keyInfo[MAX_LENGTH];//单个程序的关键信息流
} Program;

Program programs[MAX_PROGRAMS];   // 存储所有程序
int programCount = 0;             // 记录程序数量
char keepwords[MAX_PROGRAMS][MAX_LENGTH];  // 存储所有关键字和标准库函数名
int keepwordsCount = 0;           // 记录关键字和标准库函数数量

//读取 keepwords.txt 文件，加载关键字和标准库函数名
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
// 判断一个词是否为关键字或标准库函数名(此处可以优化)
int isKeepword(char *word) {
    int r=hSearch(word);
    if(r==0){
        return 0;
    }
    return 1;
}
// 获取函数信息流
void processFunctionBody(char *body, char *keyInfo) {
    int i = 0, j = 0;
    while (body[i] != '\0') { 
        if (body[i] == ' ' || body[i] == '\n' || body[i] == '\r' || body[i] == '\t') {
            i++;
            continue;
        }
        if(isalpha(body[i])||body[i]=='_'){
            char tmp[50];//临时字符串，判断是否为关键字
            int k=0;
            while (isalpha(body[i]) || body[i] == '_' || isdigit(body[i])){
                tmp[k++]=body[i++];
            }
            tmp[k]='\0';
            //printf("%s\n",tmp);
            if(body[i]=='('){//如果现在处理的tmp是一个函数名
                if(isKeepword(tmp)){//如果是关键字，保留
                strcat(keyInfo,tmp);
                j+=k;
                }else{//不是关键字，是普通函数名，改为FUNC
                    strcat(keyInfo,"FUNC");
                    j+=4;
                }
            }else if(isdigit(body[i-k-1])){//如果是0X7fffff等
                strcat(keyInfo,tmp);
                j+=k;
            }
            else{//如果不是函数名，而是普通标识符
                if(isKeepword(tmp)){//如果是关键字，保留
                strcat(keyInfo,tmp);
                j+=k;
                }
            }
            
        }else{
            keyInfo[j++] = body[i++];
        }
    }
    //keyInfo[j] = '\0';
}
// 获取程序关键信息流(program是这个程序的字符串，target是存关键信息流的字符串)
void processSingleProgram_keyInfo(char *program,char *target){
    //printf("%s\n",program);
    for(int i=0;i<3500;i++)ff[i]=NULL;
    char tmp[50000];
    char name[50];//用户定义的函数名
    //char nameList[300][50];
    int i=0,bracket=0;
    int j=0;//target的索引
    int k=0;//name的索引
    //int g=0;//namelist的索引
    while(program[i]!='\0'){
        int sig=0;
        while(program[i]!='{'&&bracket==0){
            if(program[i]=='(')sig=1;
            if(sig==0)name[k++]=program[i++];
            else i++;
        }
        name[k]='\0';
        //printf("%s\n",name);
        //strcpy(nameList[g++],name);
        if(program[i]=='{'){
            bracket++;
            tmp[j++]=program[i++];
        }
        while(bracket!=0){
            if(program[i]=='{')bracket++;
            if(program[i]=='}')bracket--;
            tmp[j++]=program[i++];
        }
        tmp[j]='\0';
        //printf("%s\n",tmp);
        char keyinfo[5000]={'\0'};
        processFunctionBody(tmp,keyinfo);
        char s[]="";
        printf("%s",s);
        //printf("%s\n",keyinfo);
        //把一个程序里每个函数的关键信息流存在哈希表里
        list *p=(list *)malloc(sizeof(list));
        unsigned int x=hash(name);
        strcpy(p->val,name);
        p->keyInfo=(char *)malloc(sizeof(keyinfo));
        strcpy(p->keyInfo,keyinfo);
        p->appearance=0;
        p->next=ff[x];
        ff[x]=p;

        j=0;k=0;bracket=0;
    }
    //现在已经得到每个函数的关键信息流，现在开始合并为程序关键信息流
    strcat(target,LLLhSearch("main")->keyInfo);//先加入main函数的关键信息流
    //printf("%s\n",LLLhSearch("main")->keyInfo);
    //开始扫描整个程序，找出main函数的一层调用函数
    //关键问题：怎么定位main函数
    i=0;
    //开始定位main函数
    char *fucktion=(char *)malloc(sizeof("mainnn"));
    strncpy(fucktion,program,4);
    if(strcmp(fucktion,"main")==0&&program[4]=='(')i=0;
    else{
        char *shit;
        int index;
        shit=strstr(program,"main");
        index=shit-program;
        while(!(program[index-1]=='}'&&program[index+4]=='(')){
            shit++;
            shit=strstr(shit,"main");
            index=shit-program;
        }
        i=index;//完成main的定位
    }
    //printf("%d\n",i);
    int bigBracket=0,smallBracket=0;//记录大小括号的个数
    while(program[i]!='{')i++;
    i++;bigBracket++;
    while(bigBracket!=0){
        //printf("%d\n",smallBracket);//printf("^^ ");
        if(program[i]=='{'){bigBracket++;}
        if(program[i]=='}'){bigBracket--;}
        if(program[i]=='('){smallBracket++;}
        if(program[i]==')'){smallBracket--;}
        if(isalpha(program[i])||program[i]=='_'){
            char tmp[20];//临时字符串，判断是否为关键字
            int h=0;
            while (isalpha(program[i]) || program[i] == '_' || isdigit(program[i])){
                tmp[h++]=program[i++];
            }
            tmp[h]='\0';
            //printf("%s\n",tmp);printf("%d\n",smallBracket);
            if(program[i]=='('&&smallBracket==0&&isKeepword(tmp)==0){//如果是函数名，且是一层调用
                //将这个函数加到关键信息流里
                if(fSearch(tmp)){
                    list *r=LLLhSearch(tmp);
                    if(r->appearance==0){
                        //printf("%s\n",tmp);
                        strcat(target,r->keyInfo);
                        r->appearance++;
                        //printf("%s\n",r->keyInfo);
                    }
                }
            }
        }else i++;
    }
    //printf("%s\n",target);
    //fprintf(ppp,"%s\n",target);
    // for(i=0;i<g;i++){
    //     list *r=LLLhSearch(nameList[i]);
    //     if(r->appearance==0&&strcmp(nameList[i],"main")!=0){
    //         r->appearance+=1;
    //         strcat(target,r->keyInfo);
    //     }
    // }
}
void processPrograms(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LENGTH];
    char c;
    int id;
    while (fscanf(file, "%d", &id) != EOF) {
        //printf("$");
        int bracket=0;//记录左右括号，判断函数是否是二层调用
        programs[programCount].id = id;
        //printf("*%d*\n",id);
        int g=0;//函数关键信息流的个数
        //char functionInfo[100][10000]={'\0'};//记录这个程序中每个函数的关键信息流
        char keyInfo[MAX_LENGTH] = {'\0'};
        char body[MAX_LENGTH] = {'\0'};
        // 读取函数体内容直到分页符
        int j=0;
        while (fscanf(file, "%c", &c) != EOF) {
            if(c=='\f')break;
            else {
                if(c== '\n' || c == '\r' || c == '\t'){continue;}
                else body[j++]=c;
            }
        }
        //char asdasdasd[10000];
        //printf("1");
        //fprintf(ppp,"%d\n",id);
        //printf("\n*%d*\n",id);
        processSingleProgram_keyInfo(body,keyInfo);
        //printf("\n*%d*\n",id);
        strcpy(programs[programCount].keyInfo, keyInfo);
        programCount++;
        // int i=0;
        // j=0;
        // while(body[i]!=')')i++;//跳过main()这几个字符
        // i++;
        // char tmp[MAX_LENGTH];
        // strcpy(tmp,body+i);
        // processFunctionBody(tmp,functionInfo[g++]);
        // //printf("%s",functionInfo[0]);break;
        // while (body[i] != '\0'){
        //     if(isalpha(body[i])||body[i]=='_'){
        //         char tmp[20];//临时字符串，判断是否为关键字
        //         int k=0;
        //         while (isalpha(body[i]) || body[i] == '_' || isdigit(body[i])){
        //         tmp[k++]=body[i++];
        //     }
        //     tmp[k]='\0';
        //     //printf("%s\n",tmp);
        //     if(body[i]=='('){
        //         if(bracket==0){
                    
        //         }
        //         bracket++;
        //     }
        //     }
        // }
        // //printf("%s\n",body);
        // processFunctionBody(body, keyInfo);
        // strcpy(programs[programCount].keyInfo, keyInfo);
        // programCount++;
    }
    fclose(file);
}

// 计算两个程序的相似度
double calculateSimilarity(char *keyInfo1, char *keyInfo2) {
    int editDistance = editdistDP(keyInfo1, keyInfo2);
    int maxLength = (strlen(keyInfo1) > strlen(keyInfo2)) ? strlen(keyInfo1) : strlen(keyInfo2);
    return 1 - (double)editDistance / maxLength;
}

// 查找并输出相似的程序
void findSimilarPrograms() {
    int clustered[MAX_PROGRAMS] = {0};  // 用于标记已处理的程序
    for (int i = 0; i < programCount; i++) {
        if (clustered[i]) continue;
        //printf("%d\n", programs[i].id);
        clustered[i] = 1;
        // 检查与当前程序相似的其他程序
        int sig=0;
        for (int j = 0; j < programCount; j++) {
            if (j!=i && calculateSimilarity(programs[i].keyInfo, programs[j].keyInfo) > SIMILARITY_THRESHOLD) {
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
    //FILE *ppp=ppp=fopen("final_fprint.txt","w");
    // 加载关键字和标准库函数名
    loadKeepwords("keepwords.txt");
    //printf("%u",hash("int"));
    //printf("%d\n",isKeepword("charads"));
    //printf("%u %u\n",hash("scanf"),hash("fscanf"));
    //printf("%d\n",hSearch("fscanf"));
    // 读取程序代码并处理
    processPrograms("codes.txt");
    //printf("%lf\n",calculateSimilarity(programs[0].keyInfo, programs[1].keyInfo));
    //printf("%s",programs[0].keyInfo);
    // 查找并输出相似的程序
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
