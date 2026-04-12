class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map: remainder -> earliest index where this remainder was seen
        unordered_map<int, int> remainderIndex;
        // Handle subarrays starting from index 0
        remainderIndex[0] = -1;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = prefixSum % k;

            if (remainderIndex.count(remainder)) {
                // Same remainder seen before — check if subarray length >= 2
                if (i - remainderIndex[remainder] >= 2) {
                    return true;
                }
            } else {
                // Only store the first occurrence to maximize subarray length
                remainderIndex[remainder] = i;
            }
        }
        return false;
    }
};