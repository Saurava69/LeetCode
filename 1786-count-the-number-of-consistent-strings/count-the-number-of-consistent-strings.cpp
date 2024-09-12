class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>s;
        for(auto &c:allowed){
            s.insert(c);
        }
        int ans = 0;
        for(auto &word:words){
            for(int i=0;i<word.length();i++){
                char ch = word[i];
                if(!s.contains(ch)){
                    break;
                }
                else{
                    if(i == word.length()-1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};