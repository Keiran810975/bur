#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct book{
    char n[100];
    char a[100];
    char b[100];
    char c[100];
}book;
struct book nnn[1000];
struct book final[1000];
int i=0;
int option;
char key[1000];
void sc(){
    FILE *op=fopen("books.txt","r");
    while(fscanf(op,"%s%s%s%s",nnn[i].n,nnn[i].a,nnn[i].b,nnn[i].c)!=EOF){
        i++;
    }
}
void swapStruct(book *x,book *y){
    struct book temp=*x;
    *x=*y;
    *y=temp;
}
void psort(book s[],int k){
    //struct book tt;
    for(int h=0;h<k-1;h++){
        for(int g=0;g<k-1;g++){
            if(strcmp(s[g].n,s[g+1].n)>0){
                swapStruct(&s[g],&s[g+1]);
            }
        }
    }
}
void search(char key[]){
    //printf("#\n");
    book temp[1000];
    int k=0;
    //printf("#\n");
    for(int j=0;j<i;j++){
        if(strstr(nnn[j].n,key)!=NULL){
            //printf("#\n");
            temp[k]=nnn[j];
            k++;
        }
    }
    psort(temp,k);
    for(int h=0;h<k;h++){
        printf("%-50s%-20s%-30s%-10s\n",temp[h].n,temp[h].a,temp[h].b,temp[h].c);
    }
}
void op0(){
    int h=0;
        for(int j=0;j<i;j++){
            if((nnn[j].n)[0]!='\0'){
                //strcpy(final[h++],name[j]);
                final[h]=nnn[j];
                h++;
            }
        }
        psort(final,h);
        FILE *ou=fopen("ordered.txt","w");
        for(int j=0;j<h;j++){
            fprintf(ou,"%-50s%-20s%-30s%-10s\n",final[j].n,final[j].a,final[j].b,final[j].c);
        }
    }
//操作
void fu(int option){
    if(option==1){
        struct book new;
        scanf("%s%s%s%s",new.n,new.a,new.b,new.c);
        nnn[i]=new;
        i++;
        //for(int j=0;j<i;j++){printf("%-50s%-20s%-30s%-10s\n",nnn[j].n,nnn[j].a,nnn[j].b,nnn[j].c);}
    }
    else if(option==2){
        //printf("#\n");
        scanf("%s",key);
        search(key);
        //for(int j=0;j<i;j++){printf("%-50s%-20s%-30s%-10s\n",nnn[j].n,nnn[j].a,nnn[j].b,nnn[j].c);}
    }
    else if(option==3){
        scanf("%s",key);
        for(int j=0;j<i;j++){
            if(strstr(nnn[j].n,key)!=NULL){
                (nnn[j].n)[0]='\0';
            }
        }
    }
}

int main(){
    sc();
    while(scanf("%d",&option)!=EOF){
        fu(option);
        //for(int j=0;j<i;j++){puts(name[j]);printf("\n");}
        if(option==0)break;
    }
    op0();
    return 0;
}