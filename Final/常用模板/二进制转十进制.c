#include<stdio.h>
#include<math.h>
#include<string.h>
char s[100];
int main() {
int n,i,len;
long long ans=0;
scanf("%s",s);
len=strlen(s);
for(i=0;i<len;i++)
ans+=(long long)(s[i]-'0')*pow(2,len-i-1);
printf("%lld",ans);
return 0;
}