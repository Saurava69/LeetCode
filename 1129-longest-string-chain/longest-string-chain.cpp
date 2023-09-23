// Memoization

// class Solution {
// public:
//     static bool cmp(string &s1,string &s2)
//     {
//         return s1.length()<s2.length();
//     }
//     int longestStrChain(vector<string>& words) {
//         unordered_map<string,int>dp;
//         sort(words.begin(),words.end(),cmp);
//         int ans=1;
//         for(auto word:words)
//         {
//             dp[word]=1;
//             for(int i=0;i<word.size();i++)
//             {
//                 string pred = word.substr(0,i) + word.substr(i+1);
//                 if(dp.find(pred) != dp.end())
//                 {
//                     dp[word] = max(dp[word],dp[pred]+1);
//                     ans = max(ans, dp[word]);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Top Down

class Solution {
public:
    static bool comp(string &a,string &b) {
        return a.size()<b.size();
    }
    bool isPredecessor(string &wordI, string &wordJ) {
        int i = 0, j = 0;
        while (i < wordI.size()) {
            if (j < wordJ.size() && wordI[i] == wordJ[j]) {
                i++;
                j++;
            } else i++;
        }
        return i == wordI.size() && j == wordJ.size();
    }

    int solve(int index,int prev,int n,vector<string>&words,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int not_take=solve(index+1,prev,n,words,dp);
        int take=INT_MIN;
        if(prev==-1 or 
        ((words[index].size()==words[prev].size()+1)
        and isPredecessor(words[index],words[prev]))){
            take=1+solve(index+1,index,n,words,dp);
        }
        return dp[index][prev+1]=max(take,not_take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,n,words,dp);
    }
};