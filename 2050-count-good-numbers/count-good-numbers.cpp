#define ll long long

class Solution {
public:
    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7     => 4 primes
  
    int p = 1e9 + 7;
    
    // calculating x^y efficeiently
    ll power(ll x, ll n) {
    if(n==0) return 1;
    //n is even
    else if(n%2 == 0)        
        return power((x*x) % p, n/2);
    //n is odd
    else                             
        return (x*power((x*x) % p, (n-1)/2)) % p;
}
  
    int countGoodNumbers(long long n) {
      ll count_of_4s = n/2;
      ll count_of_5s = n - count_of_4s;
      ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
      return (int)ans;
    }
};