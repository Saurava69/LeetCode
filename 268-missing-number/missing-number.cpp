class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0,j=nums.size()-1;i<=j;i++,j--)
        {
            if(i!=j)
            sum+=nums[i]+nums[j];
            else sum+=nums[i];
        }
        int n=nums.size(),x;
        x=n*(n+1)/2;
        return x-sum;

    }
};