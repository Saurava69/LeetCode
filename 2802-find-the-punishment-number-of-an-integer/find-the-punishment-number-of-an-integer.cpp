class Solution {
public:
    bool solve(int idx, string s, int target){
        if(idx == s.length()){
            return target == 0;
        }
        int sum = 0;
        for(int i=idx;i<=s.length();i++){
            sum=sum*10 +(s[i]-'0');
            if(sum>target) return false;
            if(solve(i+1,s,target - sum)) return true;;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++){
            string s = to_string(i*i);
            if(solve(0,s,i)){
                sum+=(i*i);
            }
        }
        return sum;
    }
};