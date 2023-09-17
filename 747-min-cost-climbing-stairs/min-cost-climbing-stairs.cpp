// class Solution {
// public:
//     int helper(int idx,vector<int>&dp,vector<int>& cost)
//     {
//        if(idx<=1){
//            return 0;
//        }
//         if(dp[idx]!=-1) return dp[idx];
//        return dp[idx]=min( cost[idx-1]+helper(idx-1,dp,cost),cost[idx-2]+helper(idx-2,dp,cost));
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         vector<int>dp(n+1,-1);
//         return helper(n,dp,cost);
//     }
// };
class Solution {
public:
    int dp[1000 + 1];
    
    int recursion(vector<int>& arr, int i)
    {
        if (i > arr.size())
            return INT_MAX - 1000;
        if (i == arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        return dp[i] = min(arr[i] + recursion(arr, i + 1), arr[i] + recursion(arr, i + 2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        memset(dp, -1, sizeof(dp));
        return min(recursion(cost, 0), recursion(cost, 1));      
    }
};