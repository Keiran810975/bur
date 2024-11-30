#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stu {
    char ss[1010];
    int cnt;
};
struct stu s[22];

int cmp(const void* a, const void* b) {
    struct stu* p = (struct stu*)a;
    struct stu* q = (struct stu*)b;
    return strlen(q->ss) - strlen(p->ss);
}

int cmp1(const void* a, const void* b) {
    struct stu* p = (struct stu*)a;
    struct stu* q = (struct stu*)b;
    return (p->cnt) - q->cnt;
}

int main() {
    int t = 0;
    int tt = 0;
    while (gets(s[t].ss) != NULL) {
        s[t].cnt = tt++;
        if (t < 19) {
            t++;
        } else if (t == 19) {
            qsort(s, 20, sizeof(s[0]), cmp);
            t++;
        } else {
            if (strlen(s[19].ss) < strlen(s[t].ss)) {
                strcpy(s[19].ss, s[t].ss);
                s[19].cnt = s[t].cnt;
                qsort(s, 20, sizeof(s[0]), cmp);
            }
        }
    }
    qsort(s, 20, sizeof(s[0]), cmp1);
    for (int i = 0; i < 20; i++) {
        printf("%s\n", s[i].ss);
    }
    return 0;
}
