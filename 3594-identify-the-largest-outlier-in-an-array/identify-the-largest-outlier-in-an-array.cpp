class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;

        for (auto &x : nums) {
            mp[x]++;
            sum += x;
        }

        int out = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int remainingSum = sum - nums[i];
            if (remainingSum % 2 != 0) continue; 
            int temp = remainingSum / 2;
            
            if (mp.count(temp)) {
                if (temp == nums[i] && mp[temp] < 2) continue;
                out = max(out, nums[i]);
            }
        }
        return out == INT_MIN ? -1 : out; 
    }
};
