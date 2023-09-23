class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int n= a.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        long long csum=a[0];
        if((sum-csum)==0) return 0;
        for(int i=1;i<n;i++)
        {
            if((sum-a[i])==2*csum){
                return i;
            }
            csum+=a[i];
        }
        return -1;
    }
};