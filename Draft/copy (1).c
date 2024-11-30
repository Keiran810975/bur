#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pb push_back
#define ll long long
#define ull unsigned long long
//#define endl puts("")
//#define endl '\n'
#define pr printf
#define sc scanf
#define scd(x) scanf("%d", &(x))
#define scdd(x, y) scanf("%d%d", &(x), &(y))
#define scddd(x, y, z) scanf("%d%d%d", &(x), &(y), &(z))
#define scdddd(x, y, z, u) scanf("%d%d%d%d", &(x), &(y), &(z), &(u))
#define scs(s) scanf("%s", s)
#define frein(s) freopen(s, "r", stdin)
#define freout(s) freopen(s, "w", stdout)
#define mem(a, k) memset(a, k, sizeof(a))
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define per(i, a, b) for (ll i = (a); i >= (b); i--)
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
typedef struct Node {
    int deg, nex[101], type, depth;
    char name[25], date[25];
} Node;
Node t[10010], ans[10010];
char s[10010], *p = s, name[25], date[25], path[10010], *ptr;
int new_num = 1001, ans_num;
int getnum() {
    int ans = 0;
    while (*p >= '0' && *p <= '9') {
        //    pr("%c ", *p);
        ans = ans * 10 + (*p - '0');
        p++;
    }
    return ans;
}
void build(int x) {
    p++;
    while (*p != ')') {
        int son = getnum();
        t[x].nex[t[x].deg++] = son;
        if (*p == '(') {
            build(son);
        }
        if (*p == ',')
            p++;
    }
    p++;
}
void bfs(int st) {
    int q[10010], front = 0, tail = 0;
    q[tail++] = st;
    while (front != tail) {
        int x_n = q[front++];
        if (t[x_n].type == 0)
            ans[ans_num++] = t[x_n];
        // pr("%s %s\n", t[x_n].name, t[x_n].date);
        rep(i, 0, t[x_n].deg - 1) { q[tail++] = t[x_n].nex[i]; }
    }
}
int find(int x) {
    int op = 0; // op为1，则为文件夹，op为0，则为文件
    if (t[x].type == 0 || *ptr == '\0')
        return x;
    char next[25];
    int cnt = 0;
    while (*ptr != '\\' && *ptr != '\0') {
        next[cnt++] = *ptr;
        ptr++;
    }
    if (*ptr == '\\') {
        ptr++;
        op = 1;
    }
    next[cnt] = '\0';
    rep(i, 0, t[x].deg - 1) {
        int x_n = t[x].nex[i];
        if (strcmp(t[x_n].name, next) == 0)
            return find(x_n);
    }
    if (op == 1) {
        t[new_num].type = 1;
        strcpy(t[new_num].name, next);
        t[x].nex[t[x].deg++] = new_num++;
        return find(new_num - 1);
    } else {
        t[new_num].type = 0;
        strcpy(t[new_num].name, next);
        strcpy(t[new_num].date, date);
        t[x].nex[t[x].deg++] = new_num++;
        return find(new_num - 1);
    }

    return find(new_num - 1);
}
void dfs(int x) {
    if (x == 0)
        return;
    rep(i, 0, t[x].deg) {
        t[t[x].nex[i]].depth = t[x].depth + 1;
        dfs(t[x].nex[i]);
    }
}
int cmp(const void *a, const void *b) {
    Node *x = (Node *)a, *y = (Node *)b;
    if (x->depth != y->depth)
        return x->depth - y->depth;
    if (strcmp(x->date, y->date) != 0)
        return strcmp(x->date, y->date);
    return strcmp(x->name, y->name);
}
int main() {
    FILE *IN = fopen("in.txt", "r");
    fgets(s, sizeof(s), IN);
    int root = getnum();
    build(root);
    int id, op;
    while (fscanf(IN, "%d%s%d%s", &id, name, &op, date) != EOF) {
        t[id].type = op;
        strcpy(t[id].name, name);
        strcpy(t[id].date, date);
    }
    int T;
    scd(T);
    while (T--) {
        sc("%s%s", path, date);
        ptr = strchr(path, '\\') + 1;
        int posi = find(root);
        if (strcmp(date, t[posi].date) > 0)
            strcpy(t[posi].date, date);
    }
    t[root].depth = 0;
    dfs(root);
    bfs(root);
    qsort(ans, ans_num, sizeof(ans[0]), cmp);
    rep(i, 0, ans_num - 1) { pr("%s %s\n", ans[i].name, ans[i].date); }
    return 0;
}