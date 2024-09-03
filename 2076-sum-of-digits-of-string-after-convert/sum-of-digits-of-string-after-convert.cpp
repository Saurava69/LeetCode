class Solution {
public:
    int getLucky(string s, int k) {
        vector<int>v;
        for(char &c:s){
            int x = c-'a' + 1;
            if(x>9){
                v.push_back(x%10);
                x/=10;
                v.push_back(x);
            }else
                v.push_back(x);
        }
        int ans = 0;
        for(int i =0; i<v.size();i++){
            ans+=v[i];
        }
        cout<<ans<<" ";
        while(ans>9 and k>1){
            vector<int>temp;
            while(ans > 0){
                temp.push_back(ans%10);
                ans/=10;
            }
            for(auto &i:temp){
                ans+=i;
            }
            cout<<ans<<" ";
            k--;
        }
        return ans;
    }
};