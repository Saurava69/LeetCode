class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string &str1, string &str2) {
        int m = str1.length();
        int n = str2.length();
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {
        memset(dp,0,sizeof(dp));
        string s2=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,s2);
    }
};