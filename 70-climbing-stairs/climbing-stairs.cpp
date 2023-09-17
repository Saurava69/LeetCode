class Solution {
public:
    int helper(int idx,vector<int>&dp)
    {
        if(idx<=2) return idx;
        if(dp[idx]!=-1) return dp[idx];

        return dp[idx]=helper(idx-1,dp)+helper(idx-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};