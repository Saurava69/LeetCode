class Solution {
public:
    int maximumProduct(vector<int>& A) {
    int n=A.size();
    sort(A.begin(),A.end());
   
    return max(A[n-1]*A[n-2]*A[n-3],A[0]*A[1]*A[n-1]);  
    }
    
};