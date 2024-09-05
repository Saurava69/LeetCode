class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(auto &x:rolls){
            sum+=x;
        }
        int sz = n + rolls.size();
        int requiredSum = mean * sz - sum;
        if(requiredSum > 6*n or requiredSum < n) return {};
        int sn = requiredSum / n;
        int sr = requiredSum % n;

        vector<int>ans(n,sn);
        int i;
        for(i=0;i<sr;i++){
            ans[i]++;
        }
        return ans;
    }
};