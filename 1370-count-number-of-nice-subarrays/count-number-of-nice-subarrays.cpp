class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;  // Base case: one way to have zero odd numbers.
        int odd_count = 0, ans = 0;
        
        for (int num : nums) {
            odd_count += (num % 2);  // Increase count if the number is odd

            // If (odd_count - k) exists in the map, it means there are subarrays
            // that end at the current index with exactly k odd numbers.
            if (count.find(odd_count - k) != count.end()) {
                ans += count[odd_count - k];
            }

            // Store the count of current odd_count
            count[odd_count]++;
        }

        return ans;
    }
};
