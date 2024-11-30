#include<stdio.h>
#include<stdlib.h>
void move(char getone, char putone) {
printf("%c-->%c\n", getone, putone);
}
void hanoit(int n, char a, char b, char c) {
if(n == 1){
move(a, c);
} else {
hanoit(n - 1, a, c, b);
move(a, c);
hanoit(n - 1, b, a, c);
}
}
int main() {
int m;
scanf("%d", &m);
hanoit(m, 'A', 'B', 'C');
return 0;
}