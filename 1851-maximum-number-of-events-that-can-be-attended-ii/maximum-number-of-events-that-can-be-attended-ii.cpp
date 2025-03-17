#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];  // Sort by end time
        });

        // DP table
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Binary search to find last non-overlapping event
        auto findLastNonOverlap = [&](int i) {
            int left = 0, right = i - 1, ans = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < events[i][0]) {  // Find event ending before i-th event starts
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return ans;
        };

        // DP iteration
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Option 1: Skip current event
                dp[i][j] = dp[i - 1][j];

                // Option 2: Take the event
                int lastNonOverlap = findLastNonOverlap(i - 1);
                int take = events[i - 1][2];  // Value of current event
                if (lastNonOverlap != -1) {
                    take += dp[lastNonOverlap + 1][j - 1];
                }

                dp[i][j] = max(dp[i][j], take);
            }
        }

        return dp[n][k];
    }
};
