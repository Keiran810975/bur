#include<stdio.h>
char Huffman[130];
char HCode[128][130];
struct cc
{
	char c;
	int count;
};
struct cc ccount[128];
struct tnode
{
	struct cc ccount;
	struct tnode *left,*right,*next;
};
struct tnode *Head;
void createHCode(struct tnode *p,char code,int level);
void insertSortLink(struct tnode *p);
int main()
{
	FILE *fp;
	char c;
	int i,j,k;
	fp=fopen("input.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		ccount[c].c=c;
		ccount[c].count++;
	}
	fclose(fp);
	
	struct tnode *p;
	for(i=0;i<128;i++)
	{
		if(ccount[i].count!=0)
		{
			p=(struct tnode*)malloc(sizeof(struct tnode));
			p->ccount=ccount[i];
			p->left=p->right=p->next=NULL;
			insertSortLink(p);
		}
	}
	
	while(Head->next!=NULL)
	{
		p=(struct tnode*)malloc(sizeof(struct tnode));
		p->ccount.count=Head->ccount.count+Head->next->ccount.count;
		p->left=Head;
		p->right=Head->next;
		p->next=NULL;
		Head=Head->next->next;
		insertSortLink(p);
	}
	
	createHCode(Head,'0',0);
	for(int i=0;i<128;i++)
	{
		if(ccount[i].count!=0)
		{
			printf("char %d, Code %s\n",i,HCode[i]);
		}
	}
}
void createHCode(struct tnode *p,char code,int level)
{
	if(level!=0)
		Huffman[level-1]=code;
	if(p->left==NULL&&p->right==NULL)
	{
		Huffman[level]='\0';
		strcpy(HCode[p->ccount.c],Huffman);
	}
	else
	{
		createHCode(p->left,'0',level+1);
		createHCode(p->right,'1',level+1);
	}
}
void insertSortLink(struct tnode *p)//频率升序
{
	if(Head==NULL)
	{
		Head=p;
		return;
	}
	struct tnode *tmp=Head;
	while(tmp->next!=NULL)
	{
		if(tmp->next->ccount.count>p->ccount.count)
		{
			p->next=tmp->next;
			tmp->next=p;
			return;
		}
		tmp=tmp->next;
	}
	tmp->next=p;
	p->next=NULL;
}