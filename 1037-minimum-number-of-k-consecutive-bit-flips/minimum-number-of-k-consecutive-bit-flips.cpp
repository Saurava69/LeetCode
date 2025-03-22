class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),ans=0,times=0;
        vector<int>isFlipped(n,0);
        for(int i=0;i<n;i++){
            if(i>=k){
                times -= isFlipped[i-k];
            }
            if((nums[i]==1 and times%2) or (nums[i]==0 and times%2==0)){
                if(i+k>n) return -1;
                ans++;
                times++;
                isFlipped[i] = 1;
            }
        }
        return ans;
    }
};