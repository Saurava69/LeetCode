class Solution {
public:
    int atMostK(vector<int>& s, int k){
        unordered_map<int,int>mp;
        int n = s.size();
        int i=0,j=0,ans=0;
        while(j<n){
            mp[s[j]]++;
            while(i<=j and j<n and mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& s, int k) {
        
        return atMostK(s,k) - atMostK(s,k-1);
    }
};