#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef struct {
    int pos;
    int type;
} Fish;

typedef struct {
    Fish fish[MAX_N];
    int front;
    int rear;
} Deque;

// 初始化双端队列
void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = 0;
}

// 在队列尾部插入元素
void pushBack(Deque *dq, Fish fish) {
    dq->fish[dq->rear++] = fish;
}

// 从队列头部弹出元素
Fish popFront(Deque *dq) {
    return dq->fish[dq->front++];
}

// 检查队列是否为空
bool isEmpty(Deque *dq) {
    return dq->front == dq->rear;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        k--; // 转为从 0 开始索引

        int types[MAX_N];
        for (int i = 0; i < n; i++) {
            scanf("%d", &types[i]);
        }

        // 使用数组和链表模拟的哈希表
        Deque fishByType[MAX_N + 1];
        for (int i = 1; i <= n; i++) {
            initDeque(&fishByType[i]);
        }

        // 初始化鱼鱼
        for (int i = 0; i < n; i++) {
            Fish fish = {i, types[i]};
            pushBack(&fishByType[types[i]], fish);
        }

        bool eaten[MAX_N] = {false}; // 标记鱼鱼是否被吃掉
        int order[MAX_N]; // 记录吃掉的顺序
        int count = 0;

        // 猫猫第一次吃掉的鱼鱼
        order[count++] = k + 1; // 保存坐标，转为从 1 开始
        eaten[k] = true;

        int currentPos = k;
        int currentType = types[k];

        while (count < n) {
            Fish nextFish;
            bool found = false;

            // 先找当前类型的鱼
            if (!isEmpty(&fishByType[currentType])) {
                while (!isEmpty(&fishByType[currentType])) {
                    nextFish = popFront(&fishByType[currentType]);
                    if (!eaten[nextFish.pos]) {
                        found = true;
                        break;
                    }
                }
            }

            // 如果没有找到当前类型的鱼，找其他鱼
            if (!found) {
                for (int i = 1; i <= n; i++) {
                    while (!isEmpty(&fishByType[i])) {
                        nextFish = popFront(&fishByType[i]);
                        if (!eaten[nextFish.pos]) {
                            found = true;
                            currentType = i; // 更新当前类型
                            break;
                        }
                    }
                    if (found) break;
                }
            }

            // 更新状态
            currentPos = nextFish.pos;
            eaten[currentPos] = true; // 标记为已吃掉
            order[count++] = currentPos + 1; // 保存坐标
        }

        // 输出结果
        for (int i = 0; i < n; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }
    return 0;
}
    