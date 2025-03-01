class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int l=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i+1]=0; 
                nums[i]= nums[i]*2;
            }
        }
        for(auto &x:nums){
            if(x!=0)
                ans[l++] =x;
        }
        return ans;
    }
};