class Solution {
public:
    int dp[10][2][2][2][1 << 10];
    string s;

    int solve(int pos, int tight, int lz, int rep, int mask) {
        if (pos == s.length()) {
            return rep;
        }

        if (dp[pos][tight][lz][rep][mask] != -1)
            return dp[pos][tight][lz][rep][mask];

        int ub = tight ? s[pos] - '0' : 9;
        int res = 0;

        for (int dig = 0; dig <= ub; dig++) {
            int newTight = (tight && dig == ub);

            if (lz && dig == 0) {
                res += solve(pos + 1, newTight, 1, 0, mask);
            } else {
                bool isUsed = (mask >> dig) & 1;

                res += solve(pos + 1, newTight, 0,
                             rep || isUsed,
                             mask | (1 << dig));
            }
        }

        return dp[pos][tight][lz][rep][mask] = res;
    }

    int numDupDigitsAtMostN(int N) {
        s = to_string(N);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, 0, 0);
    }
};