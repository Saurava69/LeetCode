class Solution {
public:
    bool count(int x){
        vector<int>d;
        while(x){
            d.push_back(x%10);
            x/=10;
        }
        int n = d.size();
        if(n%2) return false;
        int l = 0 , r =0;
        for(int i=0;i<n/2;i++){
            l+=d[i];
            r+=d[n-i-1];
        }
        return l==r;
    }
    int countSymmetricIntegers(int low, int high) {
        // return count(high) - count(low-1);

        int ans =0;
        for(int i=low;i<=high;i++){
            if(count(i)) ans++;
        }
        return ans;
    }
};