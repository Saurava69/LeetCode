class Solution
{
public:
    long long map(int side, int x, int y)
    {
        if (y == 0)
            return x;
        if (x == side)
            return side + y;
        if (y == side)
            return 3LL * side - x;
        return 4LL * side - y;
    }
    bool check(vector<long long> &t, int k, int side, int d)
    {
        int n = t.size();
        long long L = 4LL * side;
        vector<long long> extended(2 * n);
        for (int i = 0; i < n; i++)
        {
            extended[i] = t[i];
            extended[i + n] = t[i] + L;
        }
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            long long pos = extended[i];
            int idx = i;
            for (int cnt = 1; cnt < k; cnt++)
            {
                long long target = pos + d;
                auto it = std::lower_bound(extended.begin() + idx + 1, extended.begin() + i + n, target);
                if (it == extended.begin() + i + n)
                {
                    count = -1; // not enough points available from this start
                    break;
                }
                idx = it - extended.begin();
                pos = extended[idx];
                count++;
            }
            if (count == k && (extended[i] + L - pos) >= d)
                return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>> &points, int k)
    {
        int n = points.size();
        vector<long long> t(n);
        for (int i = 0; i < n; i++)
        {
            int x = points[i][0], y = points[i][1];
            t[i] = map(side, x, y);
        }
        sort(t.begin(), t.end());
        // Binary search candidate d in [0, 2*side].
        int lo = 0, hi = 2 * side, ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(t, k, side, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return ans;
    }
};