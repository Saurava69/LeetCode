class Solution {
    int m=1e9+7;
public:
    int solve(int n, int k,vector<vector<int>>&dp)
    {
        if(n<=0) return 0;
        if(k<=0) return 1;
        if(dp[n][k]!=-1) return dp[n][k];
        long long count=0;
        for(int i=0;i<=min(n-1,k);i++)
        {
            count=(count+(solve(n-1,k-i,dp))%m)%m;
        }
        return dp[n][k]=count;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
         return solve(n,k,dp);
        // dp[0][0]=1;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<k;j++)
        //     {
        //         int count=0;
        //         for(int k=0;k<min(i,j);k++)
        //         {
        //             count=(count+dp[i-1][i-j])%m;
        //         }
        //     }
        // }
        // return dp[n][k];

    }
};