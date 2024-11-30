#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
// 定义操作符优先级
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
// 检查是否是运算符
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// 反转字符串并互换括号
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
// 中缀表达式转换为后缀表达式
void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        // 如果是操作数，直接添加到后缀表达式
        if (isdigit(infix[i])) {
            postfix[k++] = infix[i];
        }
        // 左括号，入栈
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // 右括号，出栈直到遇到左括号
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // 弹出左括号
        }
        // 运算符
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    // 将栈中剩余的操作符添加到后缀表达式
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; // 结束符
}
// 计算后缀表达式的结果
int evaluatePostfix(char* postfix) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        // 如果是操作数，入栈
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        }
        // 如果是操作符，出栈操作数，计算并将结果入栈
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

// 中缀表达式转换为前缀表达式
void infixToPrefix(char* infix, char* prefix) {
    reverseAndSwapBrackets(infix);
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverseAndSwapBrackets(postfix);
    strcpy(prefix, postfix);
}

// 计算前缀表达式的结果
int evaluatePrefix(char* prefix) {
    int stack[MAX];
    int top = -1;
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        // 如果是操作数，入栈
        if (isdigit(prefix[i])) {
            stack[++top] = prefix[i] - '0';
        }
        // 如果是操作符，出栈操作数，计算并将结果入栈
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

// 前缀表达式转换为中缀表达式
void prefixToInfix(char* prefix, char* infix) {
    char stack[MAX][MAX];
    int top = -1;
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--) {
        // 如果是操作数，入栈
        if (isdigit(prefix[i])) {
            char operand[2] = {prefix[i], '\0'};
            strcpy(stack[++top], operand);
        }
        // 如果是操作符，出栈操作数，组合成中缀表达式并入栈
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

// 后缀表达式转换为中缀表达式
void postfixToInfix(char* postfix, char* infix) {
    char stack[MAX][MAX];
    int top = -1;

    for (int i = 0; postfix[i]; i++) {
        // 如果是操作数，入栈
        if (isdigit(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};
            strcpy(stack[++top], operand);
        }
        // 如果是操作符，出栈操作数，组合成中缀表达式并入栈
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

    printf("请输入一个中缀表达式: ");
    fgets(infix, MAX, stdin);

    // 去掉换行符
    infix[strcspn(infix, "\n")] = 0;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    prefixToInfix(prefix, infixFromPrefix);
    postfixToInfix(postfix, infixFromPostfix);

    printf("后缀表达式: %s\n", postfix);
    printf("前缀表达式: %s\n", prefix);
    printf("后缀表达式计算结果: %d\n", evaluatePostfix(postfix));
    printf("前缀表达式计算结果: %d\n", evaluatePrefix(prefix));
    printf("从前缀表达式转换得到的中缀表达式: %s\n", infixFromPrefix);
    printf("从后缀表达式转换得到的中缀表达式: %s\n", infixFromPostfix);

    return 0;
}
