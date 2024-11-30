#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() { 
    char s[1000001]; 
    scanf("%s", s); 
    int len = strlen(s); 
    int count[26] = {0}; 
    int max = 0; 
    for (int i = 0; i < len; i++) { 
        count[s[i] - 'a']++; 
        }
    for (int i = 0; i < 26; i++) { 
        if (count[i] > max) { 
            max= count[i]; 
        } 
        } 
        printf("%d\n", max); 
        return 0; 
    }