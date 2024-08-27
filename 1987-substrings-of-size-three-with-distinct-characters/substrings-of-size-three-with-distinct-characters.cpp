//Approach-2 (Using siding window - It can be used to solve the generalized version of the question ( k sized substring))
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        int dup   = 0;
        if(s.length() < 3) return 0;
        int mp[26] = {0};
        
        for(int i = 0; i<s.length(); i++) {
            mp[s[i]-'a']++;
            
            if(mp[s[i]-'a'] == 2)
                dup++;
            
            if(i < 2) continue;
            
            if(dup == 0) count++;
            
            //now shift right (so, (i-2)th character's frequency in current window is decreased)
            mp[s[i-2]-'a']--;
            
            if(mp[s[i-2]-'a'] == 1) //it means it had increased dup (dup++)
                dup--;
        }
        
        return count;
    }
};