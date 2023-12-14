class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=nums[0];
        int secLargest=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>largest)
            {
                secLargest=largest;
                largest=nums[i];
            }
            else
            {
                if(nums[i]>secLargest) secLargest=nums[i];
            }
        }
        return (largest-1)*(secLargest-1);
    }
};