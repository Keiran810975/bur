#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int *begin; // �׵�ַ
    int num;    // Ԫ�ظ���
} array;        // ��������

typedef struct
{
    union
    {
        array arr;
        int op; // 0Ϊmerge, 1Ϊsort��2Ϊshuffle
    } data;
    int type; // ��־������0Ϊ�������ݣ�1Ϊ��������

} node;
node stack[1000]; // ջ

void shuffle(int *mylist, int len);
int cmp(const void *a, const void *b);
int calculate(char *buf, int **res_num);

int main()
{

    int res1_num, res2_num; // ��������Ԫ�ظ���
    int *res1, *res2;       // �������
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
    int stack_num = 0; // ���ʽջ��Ԫ�ظ���
    for (int i = 0; buf[i]; i++)
    {
        if (buf[i] == '(')
        { // ������������
            stack[stack_num].type = 1;
            if (buf[i - 2] == 'g') // ��merge
                stack[stack_num++].data.op = 0;
            else if (buf[i - 2] == 'r') // ��sort
                stack[stack_num++].data.op = 1;
            else // ��shuffle
                stack[stack_num++].data.op = 2;
        }
        else if (buf[i] == ')')
        { // ������������
            if (stack[stack_num - 2].type == 1)
            {
                if (stack[stack_num - 2].data.op == 1)
                { // ��sort
                    qsort(stack[stack_num - 1].data.arr.begin, stack[stack_num - 1].data.arr.num, sizeof(int), cmp);
                    stack[stack_num - 2] = stack[stack_num - 1];
                    stack_num--;
                }
                else
                { // ��shuffle
                    shuffle(stack[stack_num - 1].data.arr.begin, stack[stack_num - 1].data.arr.num);
                    stack[stack_num - 2] = stack[stack_num - 1];
                    stack_num--;
                }
            }
            else
            { // ��һ��������merge
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
        {                    // ������
            int tmp[100];    // �ݴ����������
            int num = 0;     // ����������ָ���
            int tmp_num = 0; // �ݴ�����
            int sign = 1;    // �ж������ı�ʶ
            i++;
            while (1)
            {
                if (buf[i] == '-') // ���жϸ���
                {
                    sign = -1;
                    i++;
                }
                else
                    sign = 1;

                while (buf[i] != ',' && buf[i] != ']') // �ѵ�ǰ������ֶ���
                {
                    tmp_num = tmp_num * 10 + buf[i] - '0';
                    i++;
                }
                tmp_num *= sign;      // ��������
                tmp[num++] = tmp_num; // �����ֽ�����ʱ����
                tmp_num = 0;
                if (buf[i] == ',')
                    i++;
                else // Ϊ']'
                {
                    array temp;
                    temp.num = num;
                    temp.begin = (int *)malloc(sizeof(int) * num);
                    for (int j = 0; j < num; j++)
                    {
                        temp.begin[j] = tmp[j];
                    }
                    // ���������ջ
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

/* mylist�������ҵ�������׵�ַ��������������len�����鳤�� */
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
