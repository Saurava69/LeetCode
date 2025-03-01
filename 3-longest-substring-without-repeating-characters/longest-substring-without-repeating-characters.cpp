class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=0;
        while(i<=j and j<s.length()){
            mp[s[j]]++;
            while(mp[s[j]]>1 and i<=j){
                mp[s[i]]--;
                if(!mp[s[i]]) mp.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};