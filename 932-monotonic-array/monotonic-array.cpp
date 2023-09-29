class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int t=nums.size()-1;
        if(nums[0]>nums[t])
        {
            for(int i=1;i<=t;i++)
            {
                if(nums[i]>nums[i-1]) return false;
            }
        }
        else
        {
            for(int i=1;i<=t;i++)
            {
                if(nums[i]<nums[i-1]) return false;
            }
        }
        return true;
    }
};