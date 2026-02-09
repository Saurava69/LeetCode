class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins) {
            int res = solve(amount - coin, coins, dp);
            if (res != INT_MAX) {
                ans = min(ans, res + 1);
            }
        }

        dp[amount] = ans;
        return ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = solve(amount, coins, dp);
        return res == INT_MAX ? -1 : res;
    }
};
