/*字符画打印， 将需要打印的字符画放入同目录的source.txt文件中， 打印输出至同目录
target.txt文
件
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char n1[50] = "#include <stdio.h>\nint main(){\nprintf(", n2[5] = "\"", n3[5] =
"\\n\"", n4[50] = "\");\nreturn 0;\n}";
void WriteChar(FILE *fp, char a) {
输入
单组数据输入
fputc(a, fp);
}
void ReadChar(FILE *fpr, FILE *fpw) {
char ch;
fputs(n2, fpw);
while((ch = fgetc(fpr)) != EOF) {
if(ch == '\\' || ch == '\'' || ch == '\"')
fputc('\\', fpw);
if(ch == '%')
fputc('%', fpw);
if(ch == '\n') {
fputs(n3, fpw);
fputc(ch, fpw);
fputs(n2, fpw);
} else
fputc(ch, fpw);
}
}
int main() {
FILE *fp1 = NULL, *fp2 = NULL;
char buff[255];
fp1 = fopen("source.txt", "r");
fp2 = fopen("target.txt", "w");
fputs(n1, fp2);
ReadChar(fp1, fp2);
fputs(n4, fp2);
fclose(fp1);
fclose(fp2);
return 0;
}