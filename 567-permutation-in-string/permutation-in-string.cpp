class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp(26,0);
        int n = s2.length(), n1  = s1.size(), i= 0, j = 0;
        for(char &ch:s1){
            mp[ch - 'a']++;
        }
        while(j<n){
            mp[s2[j]-'a']--;
            if(j-i+1 == n1){
                if(mp == vector<int>(26,0)){
                    return true;
                }
                mp[s2[i] - 'a']++;
                i++;
            }
            j++;
        }
        return false; 
    }
};