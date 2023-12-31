class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int,int>mp;
        int Max=-1;
        for(int i=0;i<s.length();i++)
        {
           if( mp.find(s[i])!=mp.end())
            {
                Max=max(Max, (i-mp[s[i]]-1));
            }
            else 
                mp[s[i]]=i;
        }
        return Max;
    }
};