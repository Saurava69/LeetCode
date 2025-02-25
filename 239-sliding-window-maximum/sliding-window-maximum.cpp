class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (k == 0)
            return result;
        deque<int> w;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(!w.empty() && w.front() <= i - k)
                w.pop_front();
            while (!w.empty() && nums[w.back()] <= nums[i])
                w.pop_back();
            w.push_back(i);
            if (i >= k - 1)
                result.push_back(nums[w.front()]);
        }
        return result;
    }
};