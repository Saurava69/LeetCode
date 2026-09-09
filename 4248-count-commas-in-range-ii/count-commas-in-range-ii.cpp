#define ll long long
class Solution {
public:
    long long solve(ll n){
        if(n<1e3) return 0;
        else if(n<1e6) return n-999;
        else if(n<1e9) return (1e6-1e3) + 2*(n-1e6+1);
        else if(n<1e12) return  (1e6-1e3) + 2*(1e9-1e6) +3*(n-1e9+1);
        else  return (1e6-1e3) + 2*(1e9-1e6) +3*(1e12-1e9) + 4*(n-1e12+1);
    }
    long long countCommas(long long n) {
        if(n==1e15) return 5+solve(1e15-1);
        else return solve(n);
    }
};