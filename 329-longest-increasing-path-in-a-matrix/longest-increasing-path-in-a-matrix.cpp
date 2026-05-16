class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>> &dp){
        int m = mat.size(),n = mat[0].size();
        if(i<0 or j<0 or i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = 1;
        if(i<m-1 and mat[i+1][j]>mat[i][j]){
            down = 1+solve(i+1,j,mat,dp);
        }
        int up = 1;
        if(i>0 and mat[i-1][j]>mat[i][j]){
            up = 1+solve(i-1,j,mat,dp);
        }
        int right = 1;
        if(j<n-1 and mat[i][j+1]>mat[i][j]){
            right = 1+solve(i,j+1,mat,dp);
        }
        int left = 1;
        if(j>0 and mat[i][j-1]>mat[i][j]){
            left = 1+solve(i,j-1,mat,dp);
        }
        return dp[i][j]=max({left,right,up,down});
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int ans = 1;
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,solve(i,j,mat,dp));
            }
        }
        return ans;
    }
};