#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
void rev(char *a){
    int l=strlen(a);
    char *left=a;
    char *right=a-1+l;
    while(left<right){
        char temp=*left;
        *left=*right;
        *right=temp;
        left++;right--;
    }
}
int main(){
    return 0;
}