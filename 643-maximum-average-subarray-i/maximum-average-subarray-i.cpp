class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Compute sum of the first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window: add new element, remove old element
        for (int i = k; i < (int)nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return (double)maxSum / k;
    }
};