class Solution {
public:
int mod=1e9+7;
vector<vector<int>>memo;
int dp(int i,int steps,int len){
    if(i==0 and steps==0) return 1;
    if(i==len or i<0 or steps==0) return 0;
    if(memo[i][steps]!=-1) return memo[i][steps];

    long ans=0;
    ans+=dp(i+1,steps-1,len)%mod;
    ans+=dp(i-1,steps-1,len)%mod;
    ans+=dp(i,steps-1,len)%mod;
    return memo[i][steps]=ans%mod;
}
    int numWays(int steps, int Len) {
        int len=min(Len,steps+1);
        memo.resize(len,vector<int>(steps+1,-1));
        return dp(0,steps,Len);
    }
};