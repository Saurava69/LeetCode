class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp1(26,0),mp2(26,0);
        for(auto &c:s1) mp1[c-'a']++;
        if(s1.length()>s2.length()) return false;
        for(int i=0;i<s1.length();i++){
            mp2[s2[i]-'a']++;
        }
        if(mp1==mp2) return true;
        int inc,out;
        for(int i=s1.length();i<s2.length();i++){
            inc = s2[i]-'a';
            out = s2[i-s1.length()]-'a';
            mp2[inc]++;
            mp2[out]--;
            if(mp1==mp2) return true;
        }
        return false;
    }
};