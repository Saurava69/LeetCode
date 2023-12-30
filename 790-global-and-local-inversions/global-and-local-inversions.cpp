class Solution {
public:


    
    bool isIdealPermutation(vector<int>& nums) {
         // First approach 

        // for(int i=0;i<nums.size();i++)
        // {
        //     if(abs(nums[i] - i) > 1)
        //    {
        //        return false;
        //    } 
        // }
        // return true;

        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();

        // faster Second Approach
        if(nums.size()>2)
        {
        int maxi =-1;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            maxi=max(maxi,nums[i]);
            if(maxi>nums[i+2]) return false;
        } 
        }
        return true;       
    }
};