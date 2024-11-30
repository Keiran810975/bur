#include <stdio.h>
#include <string.h>
char s[21][1005];
int len[21];
int main()
{
	while(gets(s[20]))
	{
		int min = len[20] = strlen(s[20]), k = 20;
		for(int i = 0; i <= 20; i++)
			if(len[i] <= min)
			{
				min = len[i];
				k = i;
			}
		for(int i = k; i < 20; i++)
		{
			len[i] = len[i + 1];
			strcpy(s[i], s[i + 1]);
		}
	}
	for(int i = 0; i < 20; i++)
		puts(s[i]);
	return 0;
}
