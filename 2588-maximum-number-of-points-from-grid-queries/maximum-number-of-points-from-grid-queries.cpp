class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(queries.size());
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> query_indices;

        // Store queries with their original indices
        for (int i = 0; i < queries.size(); i++) {
            query_indices.push_back({queries[i], i});
        }

        // Sort queries based on threshold values
        sort(query_indices.begin(), query_indices.end());

        // Min-Heap (Dijkstra’s like expansion)
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;

        // Directions for moving in 4 possible ways (Right, Down, Left, Up)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Start BFS-like expansion from (0,0)
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int count = 0;

        // Process each query in increasing order
        for (auto& [threshold, index] : query_indices) {
            while (!minHeap.empty() && minHeap.top().first < threshold) {
                auto [val, cell] = minHeap.top();
                minHeap.pop();
                int r = cell.first, c = cell.second;
                count++;

                // Expand to neighbors
                for (auto [dr, dc] : directions) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        minHeap.push({grid[nr][nc], {nr, nc}});
                    }
                }
            }
            res[index] = count;
        }

        return res;
    }
};