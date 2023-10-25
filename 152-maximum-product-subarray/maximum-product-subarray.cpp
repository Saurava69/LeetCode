class Solution {
public:
unordered_map<string,int>dp;
    int rec(int i,vector<int>&nums,int n,int curr){
        if(i>=n)return curr;

        string s = to_string(i)+" "+to_string(curr);

        if(dp.find(s)!=dp.end())return dp[s];

        int a = rec(i+1,nums,n,curr*nums[i]);
        int b = rec(i+1,nums,n,nums[i]);

        return dp[s] = max({a,b,curr});
    }
    int maxProduct(vector<int>& nums) {
        dp.clear();
        return rec(1,nums,nums.size(),nums[0]);
    }
};