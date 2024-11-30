#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char str[32];
    while (gets(str) != NULL){
      int n;
      scanf("%d",&n);
      if(strcmp(str,"int")==0)printf("%d\n",n*(sizeof(int)));
      else if(strcmp(str,"char")==0)printf("%d\n",n*(sizeof(char)));
      else if(strcmp(str,"short")==0)printf("%d\n",n*(sizeof(short)));
      else if(strcmp(str,"long")==0)printf("%d\n",n*(sizeof(long)));
      else if(strcmp(str,"long long")==0)printf("%d\n",n*(sizeof(long long)));
      else printf("Err0r!\n");
      getchar();
    }

    return 0;
}