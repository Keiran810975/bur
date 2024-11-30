//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;		
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root=NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE]={{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step=0;						//ʵ�鲽�� 
FILE *Src, *Obj;
	
void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//���뵱ǰʵ�鲽�� 
	
	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	if(Step==1) 
		print1(); 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	if(Step==2) 
		print2(Root); 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	if(Step==3) 
		print3(); 			//���ʵ�鲽��3���
	if(Step>=4) 
		atoHZIP(),print4(); 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//��ʵ�鲽��1����ʼ 

void statCount(){
	Src=fopen("input.txt","r");
	Ccount[0]=1;
	char ch;
	while((ch=fgetc(Src))!=EOF){
		if(ch!='\n'){
			Ccount[ch]+=1;
		}
	}
}

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ
int cmp(const void*p1,const void*p2)
{
	struct tnode **a=(struct tnode**)p1;
	struct tnode **b=(struct tnode**)p2;
	if((*a)->weight!=(*b)->weight)	return ((*a)->weight-(*b)->weight); //比较权重 
	else return (*a)->c-(*b)->c;    //比较字典序 
}
void createHTree(){
	struct tnode *sss[128],*fff[128],*p;
	int j=0;
	for(int i=0; i<128; i++)			//构造森林 
	{
		if(Ccount[i]>0){
			p = (struct tnode *)malloc(sizeof(struct tnode)); //录入权重 
			p->c = i; p->weight = Ccount[i];
			p->left = p->right = NULL;
			sss[j++]=p;
		}
	}
	qsort(sss,j,sizeof(struct tnode *),cmp);//根据权值排序 
	int t;
	while(j>1)
	{
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->c = sss[0]->c+sss[1]->c; 				//合并
		p->weight = sss[0]->weight+sss[1]->weight; //合并 
		p->left=(struct tnode *)malloc(sizeof(struct tnode)); 
		p->right=(struct tnode *)malloc(sizeof(struct tnode));
		p->left=sss[0];		//连接 
		p->right=sss[1];		//连接
		sss[0]->weight=sss[1]->weight=0;
		t=0;
		int k=0;
		for(int i=0;i<j;i++)
		{
			if(sss[i]!=NULL && sss[i]->weight!=0)
			{
				fff[k]=(struct tnode *)malloc(sizeof(struct tnode));
				fff[k]=sss[i];
				k++;
			}								//插入合成节点************注意，有可能插在尾端  (笔者在这里脑子糊涂了一次) 
			if(t==0 && sss[i]!=NULL && sss[i]->weight!=0 && (sss[i+1]==NULL || (p->weight<sss[i+1]->weight))) 
			{
				fff[k]=(struct tnode *)malloc(sizeof(struct tnode));
				fff[k]=p;
				t++;
				k++;
			}
		}
		for(int i=0;i<128;i++)sss[i]=0;
		for(int i=0;i<k;i++)
		{
			sss[i]=(struct tnode *)malloc(sizeof(struct tnode));
			sss[i]=fff[i];
		}
		for(int i=0;i<128;i++)fff[i]=0;
		j--;	
	}
	Root=p;	//由于最后一定的是 F[0]和 F[1] 合成 p所以直接用 p 就行了 
}

//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ
void preTree(struct tnode *p,char r[],int j){
    if(p!=NULL){
		if(p->left==NULL&&p->right==NULL){
			r[j]='\0';
			strcpy(HCode[p->c],r);
			return;
		}
		r[j]='0';
		preTree(p->left,r,j+1);
		r[j]='1';
		preTree(p->right,r,j+1);
	}
}
void makeHCode(){
	char path[MAXSIZE];
	preTree(Root,path,0);
} 

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ
char huffman[1000000];
void atoHZIP(){
	Src=fopen("input.txt","r");
	Obj=fopen("output.txt","w");
	char ch;
    //fread(a,sizeof(char),1000000,Src);
	while((ch=fgetc(Src))!=EOF){	
		strcat(huffman,HCode[ch]);
	}
	strcat(huffman,HCode[0]);
	int hc=0;
	for(int i=0;huffman[i]!='\0';i++){
		hc=(hc<<1)|(huffman[i]-'0');
		if((i+1)%8==0){
			fputc(hc,Obj);
			printf("%x",hc);
			hc=0;
		}
	}
}

//��ʵ�鲽��4������

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\nԭ�ļ���С��%ldB\n",in_size);
	printf("ѹ�����ļ���С��%ldB\n",out_size);
	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
