class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prevR = nums[0];
        int maxR = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int temp = max(prevR+nums[i],maxR);
            prevR = maxR;
            maxR  = temp;
        }
        return maxR;
    }
};