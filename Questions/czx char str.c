#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char s[10000];
int less(int p,int q,int ll){
    if(p>=ll)p-=ll;
    if(q>=ll)q-=ll;
    if(s[p]>s[q])return 1;
    if(s[p]<s[q])return 0;
    return less((p+1),(q+1),ll);
}
int main(){
    scanf("%s",s);
    int ll=strlen(s);
    int min=0;
    for(int i=1;i<ll;i++){
            if(less(i,min,ll)==0)min=i;
    }
    for(int i=min;i<min+ll;i++){
        int j=i;
        if(j>=ll)j-=ll;
        printf("%c",s[j]);
    }
    return 0;
}