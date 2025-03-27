class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, h = *max_element(q.begin(), q.end()), ans = h;
        
        auto check = [&](int mid) {
            int stores_needed = 0;
            for (int x : q) {
                stores_needed += (x + mid - 1) / mid; // Equivalent to ceil(x/mid)
                if (stores_needed > n) return false; // Early stopping
            }
            return stores_needed <= n;
        };

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid)) {
                ans = mid;
                h = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans;
    }
};
