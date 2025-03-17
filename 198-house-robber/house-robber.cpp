class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0); // max rob till ith house
        if(n==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        int ans =0;
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
            ans = max(ans,dp[i]);
        }
        return dp[n-1];
    }
};