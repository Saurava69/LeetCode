#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        long long ans = LLONG_MAX; // Use LLONG_MAX instead of INT_MAX
        int n = ranks.size();
        ll l = 1, h = 1LL * ranks[0] * cars * cars;
        
        unordered_map<int, int> mp;
        for (auto x : ranks) mp[x]++; // Count occurrences of each rank
        
        auto check = [&](ll mid) -> ll {
            ll rc = 0;
            for (auto &[rank, count] : mp) {
                rc += count * (ll)sqrt(mid / (ll)rank); // Fix the way elements are accessed
            }
            return rc;
        };
        
        while (l <= h) {
            ll mid = (l + h) / 2;
            if (check(mid) >= cars) {
                ans = mid;
                h = mid - 1; // Reduce high bound
            } else {
                l = mid + 1;
            }
        }
        return ans; // Return ans instead of l
    }
};