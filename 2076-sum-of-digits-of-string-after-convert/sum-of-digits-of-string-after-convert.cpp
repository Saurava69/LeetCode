class Solution {
public:
    int getLucky(string s, int k) {
        int ans =0;
        for(char &c:s){
            int x = c-'a' + 1;
            if(x>9){
                ans+=(x%10);
                x/=10;
                ans+=(x);
            }else
                ans+=(x);
        }
        while(ans>9 and k>1){
            int ds = 0;
            while(ans > 0){
                ds+=(ans%10);
                ans/=10;
            }
            ans = ds;
            k--;
        }
        return ans;
    }
};