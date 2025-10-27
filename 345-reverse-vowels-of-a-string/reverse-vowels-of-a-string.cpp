class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' or c=='A' or c=='e' or c=='E' or c=='i' or c=='I' or c=='o' or c == 'O' or c=='u' or c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        string v = "";
        for(auto c:s) if(isVowel(c)) v.push_back(c);
        reverse(v.begin(),v.end());
        int i=0;
        for(int j=0;j<s.size();j++) {
            if(isVowel(s[j])) {
                s[j] =v[i++];
            }
        }
        return s;
    }
};