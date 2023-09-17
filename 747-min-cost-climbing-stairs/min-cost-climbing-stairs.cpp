class Solution {
public:
    int helper(int idx,vector<int>&dp,vector<int>& cost)
    {
       if(idx<=1){
           return 0;
       }
        if(dp[idx]!=-1) return dp[idx];
       return dp[idx]=min( cost[idx-1]+helper(idx-1,dp,cost),cost[idx-2]+helper(idx-2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return helper(n,dp,cost);
    }
};