class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
        visited[node] = true;
        for(auto &ngr:adj[node]){
            if(!visited[ngr]){
                visited[ngr] = true;
                dfs(ngr,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        int n = isConnected.size();
        int m = isConnected[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int N = adj.size();
        vector<bool>visited(N,0);
        int ans = 0;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                ans++;
                dfs(i,visited,adj);
            }
        }
        return ans;
    }
};