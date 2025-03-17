class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 == 1 or n == 0)
            return {};
        unordered_map<int, int> mp;
        for (auto& x : changed) {
            mp[x]++;
        }
        sort(changed.begin(), changed.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int num = changed[i];
            if (mp[num] == 0)
                continue;
            if (mp[2 * num] == 0)
                return {};
            cout << num << " ";
            ans.push_back(num);
            mp[num]--;
            mp[2 * num]--;
        }
        return ans;
    }
};