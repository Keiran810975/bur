#include<stdio.h>
#include<string.h>

int main(void)

{
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	int b[17];
	int n,sum;
	char c;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		sum = 0;
		for (int i = 0;i < 17;i++) {
			scanf("%1d", &b[i]);
		}
		scanf("%c", &c);

		for (int k = 0;k < 17;k++) {
			sum += (a[k] * b[k]);

		}
		
		switch (sum % 11)
			
		{
		case 0:if (c == '1')printf("YES\n");else printf("NO\n"); break;
		case 1:if (c == '0')printf("YES\n");else printf("NO\n");break;
		case 2:if (c == 'X')printf("YES\n");else printf("NO\n");break;
		case 3:if (c == '9')printf("YES\n");else printf("NO\n");break;
		case 4:if (c == '8')printf("YES\n");else printf("NO\n");break;
		case 5:if (c == '7')printf("YES\n");else printf("NO\n");break;
		case 6:if (c == '6')printf("YES\n");else printf("NO\n");break;
		case 7:if (c == '5')printf("YES\n");else printf("NO\n");break;
		case 8:if (c == '4')printf("YES\n");else printf("NO\n");break;
		case 9:if (c == '3')printf("YES\n");else printf("NO\n");break;
		case 10:if (c == '2')printf("YES\n");else printf("NO\n");break;

		}
	}
	

	
	
	return 0;
}