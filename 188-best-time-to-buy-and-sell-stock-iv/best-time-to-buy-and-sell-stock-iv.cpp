class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;

        // If k >= n/2, we can perform maximum transactions
        if (k >= n / 2) {
            int maxPro = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxPro += prices[i] - prices[i - 1];
                }
            }
            return maxPro;
        }
        int ans =0;
        vector<vector<int>> dp(k + 1, vector<int>(n+1, 0));
        for (int i = 1; i <= k; i++) {
            int localMax = INT_MIN;
            for (int j = 1; j <= n; j++) {
                if(j>=2)
                    localMax = max(localMax, dp[i - 1][j-2] - prices[j-2]);
                dp[i][j] = max(dp[i][j - 1], prices[j-1] + localMax);
                
            }
            ans = max(ans,dp[i][n]);
        }

        return ans;
    }
};