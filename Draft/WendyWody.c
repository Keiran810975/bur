#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int *begin; // 首地址
    int num;    // 元素个数
} array;        // 数组类型

typedef struct
{
    union
    {
        array arr;
        int op; // 0为merge, 1为sort，2为shuffle
    } data;
    int type; // 标志变量，0为数组数据，1为操作函数

} node;
node stack[1000]; // 栈

void shuffle(int *mylist, int len);
int cmp(const void *a, const void *b);
int calculate(char *buf, int **res_num);

int main()
{

    int res1_num, res2_num; // 结果数组的元素个数
    int *res1, *res2;       // 结果数组
    char buf[512];
    gets(buf);
    res1_num = calculate(buf, &res1);
    gets(buf);
    res2_num = calculate(buf, &res2);

    if (res1_num != res2_num)
        printf("Failed");
    else
    {
        for (int i = 0; i < res1_num; i++)
        {
            if (res1[i] != res2[i])
            {
                printf("Failed");
                return 0;
            }
        }
        printf("TobyWendy");
    }

    return 0;
}

int calculate(char *buf, int **res_num)
{
    int stack_num = 0; // 表达式栈中元素个数
    for (int i = 0; buf[i]; i++)
    {
        if (buf[i] == '(')
        { // 函数的左括号
            stack[stack_num].type = 1;
            if (buf[i - 2] == 'g') // 是merge
                stack[stack_num++].data.op = 0;
            else if (buf[i - 2] == 'r') // 是sort
                stack[stack_num++].data.op = 1;
            else // 是shuffle
                stack[stack_num++].data.op = 2;
        }
        else if (buf[i] == ')')
        { // 函数的右括号
            if (stack[stack_num - 2].type == 1)
            {
                if (stack[stack_num - 2].data.op == 1)
                { // 是sort
                    qsort(stack[stack_num - 1].data.arr.begin, stack[stack_num - 1].data.arr.num, sizeof(int), cmp);
                    stack[stack_num - 2] = stack[stack_num - 1];
                    stack_num--;
                }
                else
                { // 是shuffle
                    shuffle(stack[stack_num - 1].data.arr.begin, stack[stack_num - 1].data.arr.num);
                    stack[stack_num - 2] = stack[stack_num - 1];
                    stack_num--;
                }
            }
            else
            { // 上一个函数是merge
                array tmp;
                tmp.begin = (int *)malloc(sizeof(int) * (stack[stack_num - 1].data.arr.num + stack[stack_num - 2].data.arr.num));
                tmp.num = stack[stack_num - 1].data.arr.num + stack[stack_num - 2].data.arr.num;
                for (int j = 0; j < stack[stack_num - 2].data.arr.num; j++)
                {
                    tmp.begin[j] = stack[stack_num - 2].data.arr.begin[j];
                }
                for (int j = stack[stack_num - 2].data.arr.num; j < stack[stack_num - 1].data.arr.num + stack[stack_num - 2].data.arr.num; j++)
                {
                    tmp.begin[j] = stack[stack_num - 1].data.arr.begin[j - stack[stack_num - 2].data.arr.num];
                }
                stack[stack_num - 3].type = 0;
                stack[stack_num - 3].data.arr = tmp;
                stack_num -= 2;
            }
        }
        else if (buf[i] == '[')
        {                    // 是数组
            int tmp[100];    // 暂存读到的数字
            int num = 0;     // 该数组的数字个数
            int tmp_num = 0; // 暂存数字
            int sign = 1;    // 判断正负的标识
            i++;
            while (1)
            {
                if (buf[i] == '-') // 先判断负号
                {
                    sign = -1;
                    i++;
                }
                else
                    sign = 1;

                while (buf[i] != ',' && buf[i] != ']') // 把当前这个数字读完
                {
                    tmp_num = tmp_num * 10 + buf[i] - '0';
                    i++;
                }
                tmp_num *= sign;      // 带上正负
                tmp[num++] = tmp_num; // 该数字进入临时数组
                tmp_num = 0;
                if (buf[i] == ',')
                    i++;
                else // 为']'
                {
                    array temp;
                    temp.num = num;
                    temp.begin = (int *)malloc(sizeof(int) * num);
                    for (int j = 0; j < num; j++)
                    {
                        temp.begin[j] = tmp[j];
                    }
                    // 结果数组入栈
                    stack[stack_num].type = 0;
                    stack[stack_num].data.arr = temp;
                    stack_num++;
                    break;
                }
            }
        }
    }
    *res_num = stack[0].data.arr.begin;
    return stack[0].data.arr.num;
}

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

/* mylist是欲打乱的数组的首地址（或数组名），len是数组长度 */
void shuffle(int *mylist, int len)
{
    static unsigned lucky_number = 520;
    while (len > 1)
    {
        int temp = *mylist;
        *mylist = *(mylist + lucky_number % len);
        *(mylist + lucky_number % len) = temp;
        mylist++;
        len--;
        lucky_number *= 113344;
        lucky_number += 993311;
    }
}
