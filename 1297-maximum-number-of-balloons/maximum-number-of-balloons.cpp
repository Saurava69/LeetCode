class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>mp(26,0);
        for(auto &ch:text){
            mp[ch-'a']++;
        }
        return min({mp[1],mp[0],mp['l'-'a']/2,mp['o'-'a']/2,mp['n'-'a']});
        
    }
};