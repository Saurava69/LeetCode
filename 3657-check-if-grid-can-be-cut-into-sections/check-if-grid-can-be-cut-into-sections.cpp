class Solution {
public:
    int countMerged(vector<pair<int, int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        int count = 0, prev_end = -1;
        
        for (auto& interval : intervals) {
            int start = interval.first, end = interval.second;
            if (start < prev_end) {
                prev_end = max(prev_end, end);
            } else {
                prev_end = end;
                count++;
            }
        }
        return count;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_intervals, y_intervals;
        
        for (auto& rect : rectangles) {
            x_intervals.emplace_back(rect[0], rect[2]);
            y_intervals.emplace_back(rect[1], rect[3]);
        }

        return max(countMerged(x_intervals), countMerged(y_intervals)) >= 3;
    }
};