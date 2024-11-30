//加法
#include<stdio.h>
#include<string.h>
char s[10100],ss[10100];
int a[10100],b[10100];
int len;
int main()
{
scanf("%s%s",s,ss);
int l1 = strlen(s);
int l2 = strlen(ss);
if (l1 > l2)
len = l1;
else
len = l2;
for (int i = l1 - 1 ; i >= 0 ; i--)
a[l1 - i - 1] = s[i] - '0';
for (int i = l2 - 1 ; i >= 0 ; i--)
b[l2 - i - 1] = ss[i] - '0';
for (int i = 0 ; i < len ; i++)
{
a[i] = a[i] + b[i];
a[i+1]+= a[i] / 10;
}
if (a[len] != 0) len++;
while (a[len - 1] == 0 && len>1) len--;
for (int i = len - 1 ;i >= 0 ;i--)
printf("%d",a[i]);
printf("\n");
return 0;
}

//减法
#include <stdio.h>
#include <string.h>
char s[10100],ss[10100];
int a[10100],b[10100];
int len;
int main()
{
scanf("%s%s",s,ss);
int l1 = strlen(s);
int l2 = strlen(ss);
int flag = 0;
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
if ( l1 < l2 || (strcmp(s,ss) < 0 && l1 == l2) )
{
flag = 1;
for (int i = l2 - 1 ; i >= 0 ; i--)
a[l2 - i - 1] = ss[i] - '0';
for (int i = l1 - 1 ; i >= 0 ; i--)
b[l1 - i - 1] = s[i] - '0';
}
else
{
for (int i = l1 - 1 ; i >= 0 ; i--)
a[l1 - i - 1] = s[i] - '0';
for (int i = l2 - 1 ; i >= 0 ; i--)
b[l2 - i - 1] = ss[i] - '0';
}
if (l1 > l2)
len = l1;
else
len = l2;
for (int i = 0 ; i < len ; i++)
{
a[i] = a[i] - b[i];
if (a[i] < 0)
{
a[i+1]-=1;
a[i]+=10;
}
}
while (a[len - 1] == 0 && len>1) len--;
if (flag == 1) printf("-");
for (int i = len - 1 ;i >= 0 ;i--)
printf("%d",a[i]);
printf("\n");
return 0;
}

//乘法
#include<stdio.h>
#include<string.h>
char s1[50010],s2[50010];
int a[50010],b[50010],c[100010];
int main()
{
int i,j,len;
while(~scanf("%s %s",s1,s2))
{
if(s1[0]=='0'||s2[0]=='0')
printf("0\n");
else if(s1[0]=='-'&&s2[0]=='-')
{
for(i=0;i<strlen(s1)-1;i++)
s1[i]=s1[i+1];
s1[i]='\0';
for(i=0;i<strlen(s2)-1;i++)
s2[i]=s2[i+1];
s2[i]='\0';
}
else if(s1[0]=='-')
{
printf("-");
for(i=0;i<strlen(s1)-1;i++)
s1[i]=s1[i+1];
s1[i]='\0';
}
else if(s2[0]=='-')
{
printf("-");
for(i=0;i<strlen(s2)-1;i++)
s2[i]=s2[i+1];
s2[i]='\0';
}
memset(a,0,sizeof(a));
memset(b,0,sizeof(b));
memset(c,0,sizeof(c));
for(i=0;i<strlen(s1);i++)
a[i]=s1[strlen(s1)-i-1]-'0';
for(i=0;i<strlen(s2);i++)
b[i]=s2[strlen(s2)-i-1]-'0';
for(i=0;i<strlen(s1);i++)
{
for(j=0;j<strlen(s2);j++)
{
c[i+j]+=a[i]*b[j];
c[i+j+1]+=c[i+j]/10;
c[i+j]%=10;
}
}
len=strlen(s1)+strlen(s2);
while(c[len]==0) len--;
for(i=len;i>=0;i--)
printf("%d",c[i]);
printf("\n");
}
return 0;
}

//除法
#include <stdio.h>
#include <string.h>
int len1,len2;
char s1[905],s2[905];
int re[905];
void sub()
{
int i=0,j;
while(1)
{
if(s1[i]=='0') i++;
else
{
j=i;
break;
}
}
for(;i<len2;i++)
s1[i]=s1[i]-s2[i]+'0';
for(i=len2-1;i>j;i--) //低位开始检测是否小于0
if(s1[i]<'0')
{
s1[i]+=10;
s1[i-1]--;
}
}
int main()
{
int i,p;
scanf("%s%s",s1,s2);
len1=strlen(s1);
len2=strlen(s2);
if(len1<len2 || (len1==len2 && strncmp(s1,s2,len2)<0)) //如果a<b,直接输出0
printf("0\n");
p=0;
while(1)
{
re[p]=0;
while(strncmp(s1,s2,len2)>=0) //一直进行减法，直到不能减为止
{
sub();
re[p]++;
}
p++;
if(len1==len2) break;
for(i=len2-1;i>=0;i--) //在s2前面补0，以便进行减法运算
s2[i+1]=s2[i];
s2[0]='0';
len2++;
s2[len2]='\0';
}
i=0;
while(1)
{
if(re[i]==0) i++;
else break;
}
for(;i<p;i++)
printf("%d",re[i]);
return 0;
}