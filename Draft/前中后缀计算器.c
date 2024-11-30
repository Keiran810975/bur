#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// ������������ȼ�
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
// ����Ƿ��������
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// ��ת�ַ�������������
void reverseAndSwapBrackets(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}
// ��׺���ʽת��Ϊ��׺���ʽ
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        // ����ǲ�������ֱ����ӵ���׺���ʽ
        if (isdigit(infix[i])) {
            postfix[k++] = infix[i];
        }
        // �����ţ���ջ
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // �����ţ���ջֱ������������
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // ����������
        }
        // �����
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    // ��ջ��ʣ��Ĳ�������ӵ���׺���ʽ
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; // ������
}
// �����׺���ʽ�Ľ��
int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        // ����ǲ���������ջ
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        }
        // ����ǲ���������ջ�����������㲢�������ջ
        else if (isOperator(postfix[i])) {
            int b = stack[top--];
            int a = stack[top--];
            switch (postfix[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

// ��׺���ʽת��Ϊǰ׺���ʽ
void infixToPrefix(char* infix, char* prefix) {
    reverseAndSwapBrackets(infix);
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverseAndSwapBrackets(postfix);
    strcpy(prefix, postfix);
}

// ����ǰ׺���ʽ�Ľ��
int evaluatePrefix(char* prefix) {
    int stack[MAX];
    int top = -1;
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        // ����ǲ���������ջ
        if (isdigit(prefix[i])) {
            stack[++top] = prefix[i] - '0';
        }
        // ����ǲ���������ջ�����������㲢�������ջ
        else if (isOperator(prefix[i])) {
            int a = stack[top--];
            int b = stack[top--];
            switch (prefix[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

// ǰ׺���ʽת��Ϊ��׺���ʽ
void prefixToInfix(char* prefix, char* infix) {
    char stack[MAX][MAX];
    int top = -1;
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        // ����ǲ���������ջ
        if (isdigit(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            strcpy(stack[++top], operand);
        }
        // ����ǲ���������ջ����������ϳ���׺���ʽ����ջ
        else if (isOperator(prefix[i])) {
            char op1[MAX], op2[MAX];
            strcpy(op1, stack[top--]);
            strcpy(op2, stack[top--]);
            char expr[MAX] = "(";
            strcat(expr, op1);
            strncat(expr, &prefix[i], 1);
            strcat(expr, op2);
            strcat(expr, ")");
            strcpy(stack[++top], expr);
        }
    }

    strcpy(infix, stack[top]);
}

// ��׺���ʽת��Ϊ��׺���ʽ
void postfixToInfix(char* postfix, char* infix) {
    char stack[MAX][MAX];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        // ����ǲ���������ջ
        if (isdigit(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            strcpy(stack[++top], operand);
        }
        // ����ǲ���������ջ����������ϳ���׺���ʽ����ջ
        else if (isOperator(postfix[i])) {
            char op2[MAX], op1[MAX];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            char expr[MAX] = "(";
            strcat(expr, op1);
            strncat(expr, &postfix[i], 1);
            strcat(expr, op2);
            strcat(expr, ")");
            strcpy(stack[++top], expr);
        }
    }

    strcpy(infix, stack[top]);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    char infixFromPrefix[MAX], infixFromPostfix[MAX];

    printf("������һ����׺���ʽ: ");
    fgets(infix, MAX, stdin);

    // ȥ�����з�
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    prefixToInfix(prefix, infixFromPrefix);
    postfixToInfix(postfix, infixFromPostfix);

    printf("��׺���ʽ: %s\n", postfix);
    printf("ǰ׺���ʽ: %s\n", prefix);
    printf("��׺���ʽ������: %d\n", evaluatePostfix(postfix));
    printf("ǰ׺���ʽ������: %d\n", evaluatePrefix(prefix));
    printf("��ǰ׺���ʽת���õ�����׺���ʽ: %s\n", infixFromPrefix);
    printf("�Ӻ�׺���ʽת���õ�����׺���ʽ: %s\n", infixFromPostfix);

    return 0;
}
