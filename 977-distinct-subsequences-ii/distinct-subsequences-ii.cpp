class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        long long total = 0;

        for (char c : s) {
            int x = c - 'a';

            // All existing subsequences + the character itself
            long long newSubseq = (total + 1) % MOD;

            // Replace old subsequences ending in c
            total = (total - dp[x] + newSubseq + MOD) % MOD;

            dp[x] = newSubseq;
        }

        return total;
    }
};