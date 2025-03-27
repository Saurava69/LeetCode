class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>mp1,mp2;
        for(auto &x:nums) mp1[x]++;
        for(int i=0;i<nums.size();i++){
            mp2[nums[i]]++;
            if(2*mp2[nums[i]]>i+1 and 2*(mp1[nums[i]]-mp2[nums[i]])>nums.size()-i-1){
                return i;
            }
        }
        return -1;
    }
};