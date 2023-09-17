// // class Solution {
// // public:
// //     int helper(int idx,vector<int>&dp,vector<int>& cost)
// //     {
// //        if(idx<=1){
// //            return 0;
// //        }
// //         if(dp[idx]!=-1) return dp[idx];
// //        return dp[idx]=min( cost[idx-1]+helper(idx-1,dp,cost),cost[idx-2]+helper(idx-2,dp,cost));
// //     }
// //     int minCostClimbingStairs(vector<int>& cost) {
// //         int n=cost.size();
// //         vector<int>dp(n+1,-1);
// //         return helper(n,dp,cost);
// //     }
// // };
// class Solution {
// public:
    
//     // int recursion(vector<int>& dp,vector<int>& cost, int i)
//     // {
//     //     if (i == 0)
//     //         return cost[0];
//     //     if (i == 1)
//     //         return cost[1];
//     //     if (dp[i] != -1)
//     //         return dp[i];
//     //     dp[i] = cost[i]+min( recursion(dp,cost, i - 1), recursion(dp,cost, i - 2));
//     //     return dp[i];
//     // }
    
//     // int minCostClimbingStairs(vector<int>& cost) 
//     // {
//     //     int n=cost.size();
//     //     vector<int>dp(n+1,-1);
//     //     int ans = min(recursion(dp,cost, n-1), recursion(dp,cost, n-2));   
//     //     return ans;   
//     // }
   
// };
vector<int>dp (1001,-1);
class Solution {
public:

    int minCost(vector<int> & cost, int n)
    {
        if(dp[n] != -1) return dp[n];
        if(n<=1) return dp[n]=0;
        if(n==2) return dp[n]= min(cost[0] , cost[1]);
        return dp[n]=min(minCost(cost, n-1) + cost[n-1],
                   minCost(cost, n-2) + cost[n-2]);
    }
     
    int minCostClimbingStairs(vector<int>& cost) {
      int n= cost.size();
      fill(dp.begin(), dp.end(), -1);
      return minCost(cost,n);
      }  
    
};