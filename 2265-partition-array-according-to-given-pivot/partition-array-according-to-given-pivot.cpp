class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>sm,lr,eq;
       for(auto &x:nums){
        if(x<pivot) sm.push_back(x);
        else if(x==pivot) eq.push_back(x);
        else lr.push_back(x);
       }
       vector<int>ans;
       for(auto &x:sm) ans.push_back(x);
       for(auto &x:eq) ans.push_back(x);
       for(auto &y:lr) ans.push_back(y);
       return ans;
    }
};