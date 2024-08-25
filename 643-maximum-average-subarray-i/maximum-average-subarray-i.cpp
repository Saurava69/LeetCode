class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int n = nums.size();
        double mx = INT_MIN , sum =0;
        int i = 0 ,j =0;
        while(j<n){
            sum += nums[j];
            if(j-i+1 == k){
                mx = max(mx , sum/k);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};