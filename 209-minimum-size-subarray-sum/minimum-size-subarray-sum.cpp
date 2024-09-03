class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, sum = 0, n = nums.size();
        int mini = INT_MAX;

        while(j<n) {
            sum += nums[j];

            while (sum >= target) {
                mini = min(mini, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return mini == INT_MAX ? 0 : mini;
    }
};