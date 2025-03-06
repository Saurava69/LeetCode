class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeating=1,missing=-1;
        unordered_map<int,int>mp;
        for(auto &x:grid){
            for(int j=0;j<x.size();j++){
                mp[x[j]]++;
            }
        }
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(mp.find(i)==mp.end()) missing = i;
            else if(mp[i] > 1)  repeating = i;
        }
        return {repeating,missing};
    }
};