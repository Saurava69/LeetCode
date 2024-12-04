class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Record the start and end indices for each character
        unordered_map<char, int> startIndex, endIndex;
        for (int i = 0; i < s.length(); i++) {
            if (startIndex.find(s[i]) == startIndex.end()) {
                startIndex[s[i]] = i;
            }
            endIndex[s[i]] = i;
        }
        
        // Step 2: Create and merge intervals
        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, endIndex[s[i]]); // Extend the current interval
            
            if (i == end) { // If the current index matches the end of the interval
                partitions.push_back(end - start + 1); // Record the size of the partition
                start = i + 1; // Move to the next partition
            }
        }
        
        return partitions;
    }
};
