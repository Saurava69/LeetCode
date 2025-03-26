class Solution {
public:
    int n;
    vector<int> prefixSum;
    vector<vector<int>> dp;
    
    // Cost function: Sum from p+1 to i
    int cost(int p, int i) {
        return prefixSum[i] - prefixSum[p];
    }

    // Recursive Divide & Conquer DP
    void compute(int j, int left, int right, int optLeft, int optRight) {
        if (left > right) return;
        
        int mid = (left + right) / 2;
        int bestP = -1;
        dp[j][mid] = INT_MAX;

        for (int p = optLeft; p <= min(mid, optRight); p++) {
            int currCost = max(dp[j-1][p], cost(p, mid));
            if (currCost < dp[j][mid]) {
                dp[j][mid] = currCost;
                bestP = p;
            }
        }

        // Divide & Conquer: Process left and right halves
        compute(j, left, mid - 1, optLeft, bestP);
        compute(j, mid + 1, right, bestP, optRight);
    }

    int splitArray(vector<int>& nums, int k) {
        n = nums.size();
        prefixSum.assign(n + 1, 0);
        dp.assign(k + 1, vector<int>(n + 1, INT_MAX));

        // Compute prefix sums
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Base case: One partition (prefix sum)
        for (int i = 1; i <= n; i++) {
            dp[1][i] = prefixSum[i];
        }

        // Solve DP using Divide & Conquer optimization
        for (int j = 2; j <= k; j++) {
            compute(j, j, n, j - 1, n - 1);
        }

        return dp[k][n];
    }
};