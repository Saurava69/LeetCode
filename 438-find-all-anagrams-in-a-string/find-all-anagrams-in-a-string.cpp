class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen) return result;

        vector<int> pCount(26, 0), windowCount(26, 0);

        // Build frequency maps for p and the first window
        for (int i = 0; i < pLen; i++) {
            pCount[p[i] - 'a']++;
            windowCount[s[i] - 'a']++;
        }

        if (pCount == windowCount) result.push_back(0);

        // Slide the window across s
        for (int i = pLen; i < sLen; i++) {
            windowCount[s[i] - 'a']++;             // add new char
            windowCount[s[i - pLen] - 'a']--;       // remove old char
            if (pCount == windowCount) {
                result.push_back(i - pLen + 1);
            }
        }
        return result;
    }
};