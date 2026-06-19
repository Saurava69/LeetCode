class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(),ans = 0;
        vector<int>prefix(n+1,0);
        prefix[0] = 0;
        for(int i=1;i<=n;i++){
            prefix[i] = gain[i-1]+prefix[i-1];
            ans = max(ans,prefix[i]);
        }
        return ans;
    }
};