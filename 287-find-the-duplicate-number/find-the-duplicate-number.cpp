class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>a;
        for(int i=0;i<n;i++)
            a[nums[i]]++;
         for(auto i:a)
              {
                  if(i.second>1)
                      return i.first;
                  
                  }
        return -1;
    }
};