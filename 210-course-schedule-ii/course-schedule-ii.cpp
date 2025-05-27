class Solution {
public:
    vector<int>findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int>ans;
        // Build the graph and compute in-degrees
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);  // prereq → course
            inDegree[course]++;
        }

        queue<int> q;
        // Start with all nodes having in-degree 0
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;  // Number of courses we can finish

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            ans.push_back(course);
            // Reduce the in-degree of neighbors
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        vector<int>s;
        return count != numCourses?s:ans;  // Can finish all courses if no cycle
    }
};
