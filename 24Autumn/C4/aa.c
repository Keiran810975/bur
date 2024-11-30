#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double vv; 
    int v;
    int w; 
} Dish;

int compare(const void *a, const void *b) {
    Dish *dishA = (Dish *)a;
    Dish *dishB = (Dish *)b;
    if (dishA->vv < dishB->vv) return 1;
    if (dishA->vv > dishB->vv) return -1;
    return 0;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    Dish dishes[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &dishes[i].v, &dishes[i].w);
        dishes[i].vv = (double)dishes[i].v / dishes[i].w;
    }
    qsort(dishes, n, sizeof(Dish), compare);

    double max_taste_value = 0.0;
    int remain = k;

    for (int i = 0; i < n && remain > 0; i++) {
        if (dishes[i].w <= remain) {
            max_taste_value += dishes[i].v;
            remain -= dishes[i].w;
        } else {
            max_taste_value += dishes[i].vv * remain;
            remain = 0;
        }
    }

    printf("%.3f\n", max_taste_value);
    return 0;
}
