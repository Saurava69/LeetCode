class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long cnt =1;
        for(int i=2;i<=n;i++){
            long long temp= 1LL*cnt*4;
            ans =  temp + ans;
            cnt+=1;
        }
        return ans;
    }
};