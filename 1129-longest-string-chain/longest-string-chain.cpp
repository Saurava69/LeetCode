class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>dp;
        sort(words.begin(),words.end(),cmp);
        int ans=1;
        for(auto word:words)
        {
            dp[word]=1;
            for(int i=0;i<word.size();i++)
            {
                string pred = word.substr(0,i) + word.substr(i+1);
                if(dp.find(pred) != dp.end())
                {
                    dp[word] = max(dp[word],dp[pred]+1);
                    ans = max(ans, dp[word]);
                }
            }
        }
        return ans;
    }
};