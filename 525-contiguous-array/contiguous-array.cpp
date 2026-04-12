class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Map stores first occurrence of each prefix sum
        unordered_map<int, int> map;
        map[0] = -1; // handle subarrays starting from index 0
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Treat 0 as -1: equal 0s and 1s means sum = 0
            prefixSum += (nums[i] == 1) ? 1 : -1;

            if (map.count(prefixSum)) {
                maxLen = max(maxLen, i - map[prefixSum]);
            } else {
                map[prefixSum] = i;
            }
        }
        return maxLen;
    }
};