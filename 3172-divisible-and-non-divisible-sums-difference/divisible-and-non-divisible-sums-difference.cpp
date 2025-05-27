class Solution {
public:
    int differenceOfSums(int n, int m) {
        int x = int(n/m);
        int num2 = (x*(2*m + (x-1)*m))/2;
        return (n*(n+1))/2  - 2*num2;
    }
};