class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always achievable
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j]; // Can't include current num
                } else {
                    // Either take or don't take the current num
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};
