#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char str[1005];
	char s[1005];
	char format_s[105];
	char format_p[105];
	int k, x;

	gets(str);gets(format_s);scanf("%d%d",&k,&x);
	sscanf(str,format_s,s);      
	sprintf(format_p,"%%%d.%ds",k,x);        
	printf(format_p,s);               

    return 0;
}