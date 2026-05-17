class Solution { // 8 ms, faster than 91.61%
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        int len = 0;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
                len++;
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x) - sub.begin(); 
                sub[it] = x;
            }
        }
        return len;
    }
};