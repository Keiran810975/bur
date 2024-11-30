sscanf(s + i + 1, "%d", &n);//字符串的i项之后赋值给n
sscanf(input, "%s%lf", name[i], &score[i]);//input字符串给字符串和整数赋值（用空格隔开）
sprintf(aa,"%lld",e);//aa是字符串，e是整数，把e转换成字符串
sprintf(s,"%d;;::''%06d",10,13);//s成为10;;::''000013
#include<stdio.h>//自定义格式化
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