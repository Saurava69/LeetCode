class Solution {
public:
    int dp[202][20001];
    bool rec(int i, vector<int>& nums, int s, int sum) {
        if (s == sum) return true;
        if (i >= nums.size() || s > sum) return false;
        if(dp[i][s]!=-1) return dp[i][s];

        bool take = rec(i + 1, nums, s + nums[i], sum);
        bool notTake = rec(i + 1, nums, s, sum);
        return dp[i][s]=take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        return rec(0, nums, 0, sum / 2);
    }
};
