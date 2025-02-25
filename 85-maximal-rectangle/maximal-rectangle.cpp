class Solution {
public:
    int maxArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> leftsmall(n), rightsmall(n);

        // Compute left small
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftsmall[i] = (st.empty()) ? 0 : st.top() + 1;
            st.push(i);
        }

        // Clear stack for reuse
        while (!st.empty()) {
            st.pop();
        }

        // Compute right small
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightsmall[i] = (st.empty()) ? n - 1 : st.top() - 1;
            st.push(i);
        }

        // Compute max area
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix[0].size();
        int m = matrix.size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        // Convert char matrix to integer matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[i][j] = (matrix[i][j] - '0');
            }
        }

        // Compute histogram heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (heights[i][j] != 0) {
                    heights[i][j] += heights[i - 1][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans = max(ans, maxArea(heights[i]));
        }
        return ans;
    }
};
