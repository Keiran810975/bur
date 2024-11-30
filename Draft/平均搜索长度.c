#include <stdio.h>
#include <math.h>

// �������������Ⱥ�ƽ���������ȵĺ���
void binary_search_lengths(int n, double *total_length, double *average_length) {
    int total_comparisons = 0;
    int i;

    // ��������������
    for (i = 1; i <= n; i++) {
        total_comparisons += (int)log2(i) + 1;
    }

    // ����ƽ����������
    *total_length = total_comparisons;
    *average_length = (double)total_comparisons / n;
}

int main() {
    int n;
    double total_length, average_length;

    // ��������˳���ĳ���
    printf("����������˳���ĳ���: ");
    scanf("%d", &n);

    // �������������Ⱥ�ƽ����������
    binary_search_lengths(n, &total_length, &average_length);

    // ������
    printf("����������: %.0f\n", total_length);
    printf("ƽ����������: %.2f\n", average_length);

    return 0;
}
