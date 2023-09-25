class Solution {
public:
    // char findTheDifference(string s, string t) {
    //     vector<int> v(26, 0);
    //     for(auto& c:s) v[c-'a']+=1;
    //     for(auto& c:t) if(--v[c-'a']<0) return c;
    //     return '\0';
    // }

    // Xor method
    char findTheDifference(string s, string t) {
        char ret ='\0';
        for (auto &c: s) ret^=c;
        for (auto &c: t) ret^=c;
        return ret;
    }

    //Summation Method
    // char findTheDifference(string s, string t) {
    //     int sum = 0;
    //     for (auto &c: t) (sum+=c)%=256;
    //     for (auto &c: s) (sum-=c)%=256;
    //     return (char)sum;
    // }
};