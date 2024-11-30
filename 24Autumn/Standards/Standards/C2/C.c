#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int deap[100005], tag = 0;

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void up(int x){
	while(x > 1 && deap[x] > deap[x / 2]){
		swap(&deap[x], &deap[x / 2]);
		x /= 2; 
	} 
}

void down(int x){
	while(x * 2 <= tag){
		int t = x * 2;
        if (t + 1 <= tag && deap[t + 1] > deap[t]) 
            t++;
        if (deap[t] <= deap[x])
            break;
        swap(&deap[x], &deap[t]);
        x = t;
	}
} 
int main(){
	int n, op, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &op);
		if(op == 1){
			int num;
			scanf("%d", &num);
			tag++;
			deap[tag] = num;
			up(tag);
		}
		else if(op == 2){
			swap(&deap[1], &deap[tag]);
			tag--;
			down(1);
		} 
		else{
			printf("%d\n", deap[1]);
		} 
	}
	while(tag != 0) {
		printf("%d ", deap[1]);
		swap(&deap[1], &deap[tag]);
		tag--;
		down(1);
	}
	return 0; 
}
