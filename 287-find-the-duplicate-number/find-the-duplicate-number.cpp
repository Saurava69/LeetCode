class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>a;
        for(int i=0;i<n;i++){
            a[nums[i]]++;
            if(a[nums[i]]>1)
                    return nums[i];      
        }
        return -1;
    }
};