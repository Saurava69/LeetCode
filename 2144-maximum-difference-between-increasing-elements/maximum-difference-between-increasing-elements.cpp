class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n,INT_MAX),maxi(n,INT_MIN);
        int minT=INT_MAX,maxT=INT_MIN;
        mini[0] = nums[0];
        maxi[n-1] = nums[n-1];
        bool flag = false;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) flag=true;
            minT = min(minT,nums[i-1]);
            maxT = max(maxT,nums[n-i-1]);
            mini[i] = minT;
            maxi[n-i-1] = maxT;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(maxi[i] - mini[i]));
        }
        return flag?ans:-1;
    }
};