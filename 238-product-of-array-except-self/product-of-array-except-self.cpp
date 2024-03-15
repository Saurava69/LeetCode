class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct=1;
        int zeroes=0;
        int zeroProduct=1;
        vector<int>ans(nums.size(),0);
        for(int &x:nums)
        {
            if(x==0){
                zeroes++;
            }
            if(x!=0)    zeroProduct*=x;
            totalProduct*=x;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 and zeroes==1)
            {
                ans[i]=zeroProduct;
            }
            else
            {
                if(zeroes>1) ans[i]=0;
                else
                ans[i]=totalProduct/nums[i];
            }
        }
        return ans;
    }
};