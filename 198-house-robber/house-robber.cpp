// class Solution {
// public:
//     int rob(vector<int>& A) {
//         vector<int> dp(size(A),-1);
//         return rob(A, dp, 0);
//     }
//     int rob(vector<int>& A, vector<int>& dp, int i) {
//         if(i >= size(A)) return 0;
//         if(dp[i] != -1) return dp[i];
//         return dp[i] = max(rob(A, dp, i+1), A[i] + rob(A, dp, i+2));
//     }
// };
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size()==1)return nums[0];
//         vector<int>dp(nums.size());
//         dp[0]=nums[0];
//         dp[1]=max(nums[0],nums[1]);
//         for(int i=2;i<nums.size();i++){
//             dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
//         }
//         return dp[nums.size()-1];
//     }
// };
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prev_ans2=nums[0], prev_ans=max(nums[0],nums[1]),curr_ans=prev_ans;
        
        for(int i = 2; i < n; i++){
            curr_ans = max(prev_ans, prev_ans2 + nums[i]);
            prev_ans2 = prev_ans;
            prev_ans = curr_ans;
        }
        return curr_ans;
    }
};