class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int left = 0;
        int right = cols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find row with max element in this column
            int maxRow = 0;
            for (int r = 0; r < rows; r++) {
                if (mat[r][mid] > mat[maxRow][mid]) {
                    maxRow = r;
                }
            }

            int midVal = mat[maxRow][mid];
            int leftVal  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightVal = (mid + 1 < cols) ? mat[maxRow][mid + 1] : -1;

            // Check if it's a peak
            if (midVal > leftVal && midVal > rightVal) {
                return {maxRow, mid};
            }

            // Move towards bigger neighbor
            if (leftVal > midVal) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {-1, -1}; // theoretically never hit due to guaranteed peak
    }
};
