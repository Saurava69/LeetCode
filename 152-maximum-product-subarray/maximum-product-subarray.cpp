// class Solution {
// public:
// unordered_map<string,int>dp;
//     int rec(int i,vector<int>&nums,int n,int curr){
//         if(i>=n)return curr;

//         string s = to_string(i)+" "+to_string(curr);

//         if(dp.find(s)!=dp.end())return dp[s];

//         int a = rec(i+1,nums,n,curr*nums[i]);
//         int b = rec(i+1,nums,n,nums[i]);

//         return dp[s] = max({a,b,curr});
//     }
//     int maxProduct(vector<int>& nums) {
//         dp.clear();
//         return rec(1,nums,nums.size(),nums[0]);
//     }
// };
// class Solution {
// public:

//     int maxProduct(vector<int>& nums) {
//         // int maxi = INT_MIN;
//         // int prod=1;

//         // for(int i=0;i<nums.size();i++)
//         // {
//         //   prod*=nums[i];
//         //   maxi=max(prod,maxi);
//         //   if(prod==0)
//         //    prod=1;
//         // }
//         // prod=1;
//         // for(int i=nums.size()-1;i>=0;i--)
//         // {
//         //   prod*=nums[i];

//         //   maxi=max(prod,maxi);
//         //   if(prod==0)
//         //    prod=1;
//         // }
//         // return maxi;
        
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxSoFar = ans, minSoFar = ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maxSoFar,minSoFar);

            maxSoFar = max(maxSoFar*nums[i],nums[i]);
            minSoFar = min(minSoFar*nums[i],nums[i]);

            ans = max(maxSoFar,ans);
        }
        return ans;
    }
};