#include <stdio.h> 
#include <string.h> 
char s[100];
int main() { 
int T; 
scanf("%d", &T); 
while (T--) { 
    long long int m, n; 
scanf("%lld %lld", &m, &n); 
getchar();
scanf("%s",&s); 
int len = strlen(s); 
long long int num = 0; 
for (int i = 0; i < len; i++) { 
    if (s[i] >= '0' && s[i] <= '9') { 
        num = num * m + (s[i] - '0'); 
    } 
    else if (s[i] >= 'A' && s[i] <= 'Z') { 
        num = num * m + (s[i] - 'A' + 10); 
    } 
    } 
    char a[100]; 
    int ccc = 0; 
    while (num) { 
        long long int rem;
        if(n>0){
            rem=num%n;
        
        if (rem >= 0 && rem <= 9) { 
            a[ccc++] = '0' + rem;
        } else if (rem >= 10 && rem <= 35) { 
            a[ccc++] = 'A' + rem - 10; 
        } 
        num /= n; 
        } 
        if(n<0){
        if(num>0)
        rem=num%n;
        else
        rem=num%n-n; 
        if (rem >= 0 && rem <= 9) { 
            a[ccc++] = '0' + rem;
        } 
        else if (rem >= 10 && rem <= 35) { 
            a[ccc++] = 'A' + rem - 10; 
        } 
        if(num>0)
        num=num/n;
        else
        num=(num/n)+1;
        }
    } 
        for (int i = ccc - 1; i >= 0; i--) { 
            printf("%c", a[i]); 
            } 
        printf("\n"); 
        }
        return 0; 
        }