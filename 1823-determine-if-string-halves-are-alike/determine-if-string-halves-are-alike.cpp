class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> m = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
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