class Solution {
public:
    bool isValidSplit(vector<int>& nums, int k, int maxSum) {
        int subarrays = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValidSplit(nums, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};