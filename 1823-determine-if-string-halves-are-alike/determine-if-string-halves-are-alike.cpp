class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_map<char,int>m;
        string s1="aeiouAEIOU";
        for(auto& ch:s1) m[ch]++;
        int i=0,j=s.length()-1;
        int a=0,b=0;
        while(i<=j)
        {
            if(m.find(s[i++])!=m.end()) a++;
            if(m.find(s[j--])!=m.end()) b++;
        }
        return a==b;
        
    }
};