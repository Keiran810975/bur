#include <iostream>
#include <cstring>
using namespace std;

char t[] = "1145141919810";
char s[100010];
int g[100010];
int l = strlen(t);

void dp() {
    g[0] = 0;
    int ll = strlen(s);
    for (int i = 1; i <= ll; i++) {
        int maxx = 0;
        int match_count = 0;
        for (int j = max(0, i - l); j <= i - 1; j++) {
            if (i - j <= l) {
                match_count = 0;
                for (int k = 0; k < i - j; k++) {
                    if (s[j + k] == t[k]) {
                        match_count++;
                    }
                }
            }
            maxx = max(maxx, g[j] + match_count);
        }
        g[i] = maxx;
    }
    
    printf("%lld\n", g[ll]);
}

int main() {
    int tt;
    scanf("%d", &tt);
    
    while (tt--) {
        scanf("%s", s);
        dp();
    }
    
    return 0;
}
