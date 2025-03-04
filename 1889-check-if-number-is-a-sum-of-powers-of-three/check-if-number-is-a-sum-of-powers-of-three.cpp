class Solution {
public:
    bool checkPowersOfThree(int n) {
        string s = "";
        while(n>0){
            int bit = n%3;
            char c = bit + '0';
            s.push_back(c);
            n/=3;
        }
        for(auto c:s){
            if(c-'0'>1) return false;
        }
        return true;
    }
};