class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0,j=0,ans=0;
        while(i<=j and j<fruits.size()){
            mp[fruits[j]]++;
            if(mp.size()<=2) ans = max(ans,j-i+1);
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};