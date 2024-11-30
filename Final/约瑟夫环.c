#include <stdio.h>
int main() {
	int n, q, i = 0, count = 1, flag = 0;
	printf("number:");
	scanf("%d", &n);//输入人数
	getchar();
	printf("m=");
	scanf("%d", &q);//输入报到哪个数死
	int a[n];
	for (i = 0; i < n; i++) {//给每个人设置“生”的状态
		a[i] = 0;
	}
	i = 0;
	printf("kill:");
	while (1) {
		if (flag == n - 1) break;//当只剩下一个人时，跳出循环
		if (a[i] == 1) i++;//如果该人为死亡的状态，则跳过该人
		else {
			if (count == q) {//满足被杀死的条件
				a[i] = 1;//设置死亡状态
				flag++;//死亡人数加一
				printf("%d ", i);//输出这一次死亡的人的编号
				count = 1;//重置报数
				i++;//移动到下一个人开始
			} else {//不满足被杀死的状态
				count++;//继续报数
				i++;
			}
		}
		if (i == n) i = 0;//由于数组下标从0开始，所以当i=n时，应该是移动到第一个人了
	}
	printf("\nsurvive:");
	for (i = 0;; i++) {
		if (a[i] != 1) {//输出最后存活的人
			printf("%d", i);
			break;
		}
	}
	return 0;
}