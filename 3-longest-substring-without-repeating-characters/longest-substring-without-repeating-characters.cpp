class Solution {
public:
int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0, i = 0, j = 0;
        unordered_set<char> charSet;

        while (i < n && j < n) {
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j++]);
                ans = max(ans, j - i);
            } else {
                charSet.erase(s[i++]);
            }
        }

        return ans;
    }
};