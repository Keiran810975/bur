#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
#define MIN ((x<y)?(x:y))
typedef struct queue{
	int time[3000];
}queue;
struct queue q;
int head=1,tail=1;
int n,m,op;
int min(int a,int b){
    return a<b?a:b;
}
void chooseOP1(int n)
{
	if(n<21)	op=3;    //开放窗口个数 
	else if(n>=21 && n<28)		op=4;
	else op=5;
}
void chooseOP2(int n)
{
	if(n<28)	op=3;    //开放窗口个数 
	else if(n>=28 && n<35)		op=4;
	else op=5;
}
int numCustom[100];
int type[10000];
int w[6];      //五个服务窗口
int sum=0;
int main(){	
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&numCustom[i]);
        sum+=numCustom[i];
    }
    for(int i=0;i<sum;i++){
            scanf("%d",&type[i]);
    }
    int free=3;
    chooseOP1(tail-head);
    int index=0;
	for(int i=0;i<n;i++){
		tail+=numCustom[i];    //队尾增加 
        int x=op;
		chooseOP1(tail-head);	
        if(op-free>0)free=op;
		for(int j=head;j<min(head+free,tail);j++){
			printf("%d : %d\n",j,q.time[j]);   //输出已经在窗口的客户
		}
		for(int j=head+free;j<tail;j++){
			q.time[j]++;              //等待的客户周期加1 
		}	
		head=min(head+free,tail);  
		free=0;     //出队 
		//chooseOP1(tail-head);
        
	}
	while(head<tail){
		chooseOP2(tail-head);
		for(int i=head;i<min(head+op,tail);i++){
			printf("%d : %d\n",i,q.time[i]);   //输出已经在窗口的客户
		}
		for(int i=head+op;i<tail;i++){
			q.time[i]++;              //等待的客户周期加1 
		}	
		head=min(head+op,tail);       //出队 
		chooseOP2(tail-head);
	}
	return 0;
}
