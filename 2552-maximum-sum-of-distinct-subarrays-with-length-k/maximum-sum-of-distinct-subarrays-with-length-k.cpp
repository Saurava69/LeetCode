class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0;
        long long maxSum = 0;

        // Build the first window of size k
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            windowSum += nums[i];
        }
        // Check if the first window has all distinct elements
        if ((int)freq.size() == k) {
            maxSum = windowSum;
        }

        // Slide the window across the rest of the array
        for (int i = k; i < (int)nums.size(); i++) {
            // Add the new element entering the window
            freq[nums[i]]++;
            windowSum += nums[i];

            // Remove the element leaving the window
            int outVal = nums[i - k];
            freq[outVal]--;
            if (freq[outVal] == 0) {
                freq.erase(outVal);
            }
            windowSum -= outVal;

            // Window is valid only when all k elements are distinct
            if ((int)freq.size() == k) {
                maxSum = max(maxSum, windowSum);
            }
        }
        return maxSum;
    }
};