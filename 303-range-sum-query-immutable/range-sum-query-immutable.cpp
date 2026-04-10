class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        // Build prefix sum array where prefix[i] = sum of nums[0..i-1]
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};