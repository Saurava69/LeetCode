class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size(),ans=0,mask=0;
        while(j<n){
            cout<<j<<" ";
            while((mask&nums[j])!=0){
                mask^=nums[i];
                i++;
            }
            
            mask|=nums[j];
            cout<<j<<" ";
            ans=max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};