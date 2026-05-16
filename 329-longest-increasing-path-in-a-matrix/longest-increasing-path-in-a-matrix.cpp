//clean code
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> dp;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(matrix, i, j, m, n));
            }
        }
        return result;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if (dp[i][j] != 0) return dp[i][j];
        int best = 1;
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, ni, nj, m, n));
            }
        }
        dp[i][j] = best;
        return best;
    }
};