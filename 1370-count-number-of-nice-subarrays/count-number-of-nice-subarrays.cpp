class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            k -= nums[right] % 2;  // Reduce k when an odd number is found
            
            while (k < 0) {  // If we exceed k, shrink from the left
                k += nums[left] % 2;
                left++;
            }
            
            ans += (right - left + 1);  // Count valid subarrays
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
