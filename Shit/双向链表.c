#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct double_list{
	int data ;
	struct double_list *prev ;
	struct double_list *next ;
}DL ; 
DL *CreateDLNode(int data){
	DL *p = (DL *)malloc(sizeof(DL));
	if(NULL == p)
	{
		printf("create dl node fair!\n");
		return NULL ;
	}
	p->data = data ;
	p->next = NULL ;
	p->prev = NULL ;
}
 
//双向链表的尾插 
void DLInsertTail(DL *header , DL *new){
	DL *p = header ;
	while(NULL != p->next){
		p = p->next ;
	}
	p->next = new ;
	new->prev = p;
}
 
//双向链表的头插(也就是插在两个节点之间的插入方式)
void DLInsertHead(DL *header , DL *new){
	new->next = header->next ; 
	if(NULL != header->next) 
		header->next->prev = new ; //节点1的prev指针指向新节点的地址 
	header->next = new ;
	new->prev = header ;
}
 
//双向链表的正向遍历 
void DLPrintList(DL *header){
	DL *p = header ;
	while(NULL != p->next){
		p = p->next ;
		printf("%d ",p->data);
	}
}
 
//双向链表的反向遍历 
void double_list_for_each_nx(DL *header){
	DL *p = header ;
	while(NULL != p->next){
		p = p->next ;	
	} 
	while(NULL != p->prev){
		printf("%d ",p->data);
		p = p->prev ;
	}
}
 
//双向链表节点的删除
int double_list_delete_node(DL *header , int data){
	DL *p = header;
	while(NULL != p->next){
		p = p->next ;
		if(p->data == data){
			if(p->next != NULL){
				p->next->prev = p->prev ;
				p->prev->next = p->next ;
				free(p);
			}
			else{
				p->prev->next = NULL ;
				free(p); 
			}
			return 0 ;
		}
	}
	printf("\nomious\n");
	return -1 ;	
} 
 
int main(){
	int i ;
	DL *header = CreateDLNode(0);
	//printf("666");
	for(i = 0 ; i < 10 ; i++)
	{
		//双向链表的尾插 
		DLInsertTail(header,CreateDLNode(i));
		//双向链表的头插 
		//DLInsertHead(header,CreateDLNode(i));
	}
	//双向链表的正向遍历 
	//printf("双向链表的正向遍历:");
	double_list_delete_node(header,5);
	DLPrintList(header);
//	double_list_delete_node(header,9);
	double_list_delete_node(header,5);
	printf("\n");
	//printf("双向链表的反向遍历:");
	double_list_for_each_nx(header);
	return 0 ;
}