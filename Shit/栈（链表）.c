#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
void push(int x,Node *top){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=top;
    top=temp;
}
void pop(Node *top){
    Node *temp;
    if(top==NULL)return;
    temp=top;
    top=top->next;
    free(temp);
}
int main(){

    return 0;
}