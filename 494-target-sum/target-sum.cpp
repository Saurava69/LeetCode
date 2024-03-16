class Solution {
public:
    int solve(int i,int n,int sum,vector<int>&nums,int t)
    {
        if(sum==t and i==n) return 1;
        if(i>=n) return 0;
        int negTake=solve(i+1,n,sum-nums[i],nums,t);
        int posTake=solve(i+1,n,sum+nums[i],nums,t);
        return negTake+posTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return solve(0,nums.size(),0,nums,target);
    }
};