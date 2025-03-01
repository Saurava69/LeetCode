class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int ans = 0;
            int i=0,j=0,k_count=0;
            while(i<=j and j<nums.size()){
                if(nums[j]==0 and k_count<=k){
                    k_count++;
                }
                while(nums[j] == 0 and k_count>k and i<=j){
                    if(nums[i] == 0 ){
                        k_count--;
                    }
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
            return ans;
        }
};