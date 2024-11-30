#include <stdio.h>
#include <string.h>
int dp[2005][2005];
int longest_common_substring(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int longest = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return longest;
}
int dp2[2005][2005];
int longest_common_subsequence(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp2[i][j] = dp2[i - 1][j - 1] + 1;
            } else {
                dp2[i][j] = (dp2[i - 1][j] > dp2[i][j - 1]) ? dp2[i - 1][j] : dp2[i][j - 1];
            }
        }
    }

    return dp2[len1][len2];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char s1[2005], s2[2005];
        scanf("%s", s1);
        scanf("%s", s2);
        
        int lcs_length = longest_common_substring(s1, s2);
        int lcss_length = longest_common_subsequence(s1, s2);
        
        printf("%d %d\n", lcs_length, lcss_length);
    }
    
    return 0;
}