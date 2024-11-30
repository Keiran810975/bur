## 思路

1. 根据`n`计算鼠鼠数量，进行初始化
2. 进行`n`轮循环赛
   1. 每轮比赛开始前按照`id`大小进行`qsort`
   2. 根据当前 参赛鼠数/2 来进行“鼠鼠互搏”
      1. 更新每个鼠鼠遇到的最强对手的实力值
      2. 淘汰实力值较小的鼠鼠（把该鼠鼠的`id`置为最大（10^9^+1），因此需要`yuanid`来记录鼠鼠的初始`id`）
3. 按照`yuanid`进行`qsort`
4. 输出

## 代码

```c
#include <stdio.h>
#include <stdlib.h>

struct mouse{
    int yuanid, id, p, max;
};

struct mouse mouses[1048580];

int mypow(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        ans *= 2;
    }
    return ans;
}

int cmp(const void *a, const void *b){
    struct mouse *pa = (struct mouse *)a;
    struct mouse *pb = (struct mouse *)b;
    if(pa->id < pb->id){
        return -1;
    }else{
        return 1;
    }
}
int cmp1(const void *a, const void *b){
    struct mouse *pa = (struct mouse *)a;
    struct mouse *pb = (struct mouse *)b;
    if(pa->yuanid < pb->yuanid){
        return -1;
    }else{
        return 1;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        int n;
        scanf("%d", &n);
        int num = mypow(n);     // 一共有num个鼠鼠
        int yuanNum = num;      // 记录num
        for(int j=1; j<=num; j++){
            scanf("%d", &mouses[j].p);
            mouses[j].id = mouses[j].yuanid = j;
            mouses[j].max = 0;
        }

        for(int j=1; j<=n; j++){
            // 按照id大小进行排序
            if(j == 1){
                qsort(mouses, num+1, sizeof(struct mouse), cmp);
            }else{
                qsort(mouses, num*2+1, sizeof(struct mouse), cmp);
            }

            num /= 2;
            for(int k=1; k<=num; k++){      // 1 <= k <= 2^n-i
                // 更新遇到的最强对手
                if(mouses[2*k-1].p > mouses[2*k].max){
                    mouses[2*k].max = mouses[2*k-1].p;
                }
                if(mouses[2*k].p > mouses[2*k-1].max){
                    mouses[2*k-1].max = mouses[2*k].p;
                }

                // 实力值较小者被淘汰
                if(mouses[2*k-1].p < mouses[2*k].p){
                    mouses[2*k-1].id = 1000000001;
                }else{
                    mouses[2*k].id = 1000000001;
                }
            }
        }

        // 按照yuanid排序
        qsort(mouses, yuanNum+1, sizeof(struct mouse), cmp1);
        // 输出
        for(int j=1; j<=yuanNum; j++){
            printf("%d ", mouses[j].max);
        }
        puts("");
    }

    return 0;
}
```



