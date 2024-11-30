#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
char *multiply(char *num1, char *num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
    {
        char *result = (char *)malloc(2);
        strcpy(result, "0");
        return result;
    }
    int *result = (int *)calloc(len1 + len2, sizeof(int));
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }
    int i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;

    char *finalResult = (char *)malloc(len1 + len2 - i + 1);
    int k = 0;
    while (i < len1 + len2)
    {
        finalResult[k++] = result[i++] + '0';
    }
    finalResult[k] = '\0';
    free(result);
    return finalResult;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char a[5000], b[5000];
        scanf("%s%s", a, b);
        printf("%s\n", multiply(a, b));
    }
    return 0;
}