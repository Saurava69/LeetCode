class Solution {
public:
    int rob1(vector<int>&nums,int i,int n){
        int prev = 0;
        int maxR = 0;
        for(int j = i;j<n;j++){
            int temp = max(nums[j]+prev,maxR);
            prev = maxR;
            maxR = temp;
        }
        return maxR;
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);
        return max(rob1(nums,0,n-1),rob1(nums,1,n));
    }
};