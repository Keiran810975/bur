#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(int *x,int *y){
    int temp=*y;
    *y=*x;
    *x=temp;
}
int priQ[100000];//��(С����)
int len;//��¼�ѵĳ���
void put(int x){//�����������,����+1�����öѵĸ��ӽڵ��ϵ,һ�δ��븸�ױȽϣ�����ȸ���С�ͽ����������Ƚϣ�ֱ���ȸ��״���˸��ڵ�Ϊֹ
    int f;
    len++;
    priQ[len]=x;
    int b=len;
    while(b!=1&&priQ[b]<priQ[b/2]){
        swap(&priQ[b],&priQ[b/2]);
        b=b/2;
    }
}
int get(){//ȡ���Ѷ�
//����-1�������һ���ᵽ��һ�������öѵĸ��ӽڵ��ϵ���û�����һ����������ӱȽϣ�
//����Ⱥ��Ӵ󣬾�����������֮���С��һ��������ֱ��û�ж��ӻ�ȶ���СΪֹ
    int x=priQ[1];
    priQ[1]=priQ[len];
    len--;
    int f,c;
    while(2*f<=len){
        if(2*f+1>len||priQ[2*f]<priQ[2*f+1])c=2*f;
        else c=2*f+1;
        if(priQ[f]<priQ[c]){
        swap(&priQ[f],&priQ[c]);
        f=c;
    }else return x;
    }
    return x;
}
int main(){
    put(1);
    put(3);
    put(4);
    put(2);
    put(7);
    printf("%d\n",len);
    get();
    get();
    for(int i=0;i<len;i++)printf("%d ",priQ[i]);
    printf("\n%d\n",len);
    return 0;
}