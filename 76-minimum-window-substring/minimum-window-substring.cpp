class Solution {
public:
    bool match(unordered_map<char, int>& window, unordered_map<char, int>& freq_t) {
        for (auto& [ch, count] : freq_t) {
            if (window[ch] < count) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";  // Edge case

        unordered_map<char, int> freq_t, window;
        for (char ch : t) freq_t[ch]++;  // Store frequency of chars in `t`

        int i = 0, j = 0, n = s.length();
        int minLen = INT_MAX, startIdx = -1;

        while (j < n) {
            window[s[j]]++;  // Expand window

            // Shrink window when valid
            while (match(window, freq_t) && i <= j) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                window[s[i]]--;  // Shrink window
                if (window[s[i]] == 0) window.erase(s[i]);  // Remove char if count is 0
                i++;
            }
            j++;  // Expand right pointer
        }

        return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
    }
};
