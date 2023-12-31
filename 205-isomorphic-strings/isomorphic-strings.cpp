class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map< pair<char,char>, int >mp;
        unordered_set<char>st;
        unordered_set<char>st2;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
            st2.insert(t[i]);
            pair<int,int>a;
            a.first=s[i];
            a.second=t[i];
            mp[a]++;

        }
        return (st.size()==mp.size() and st2.size()==st.size()) ;
    }
};