class Solution {
private:
    int find(int node){
        if(parent[node]==-1) return node;
        return parent[node] = find(parent[node]);
    }

    void Union(int node1,int node2){
        int rootX = find(node1);
        int rootY =  find(node2);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
        return;
    }
public:
    vector<int>parent;
    vector<int>rank;

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n,-1);
        rank.resize(n,0);
        vector<int>componentCost(n,-1);
        for(auto &edge:edges){
            Union(edge[0],edge[1]);
        }
        //Calculate Cost
        for(auto &edge:edges){
            int root = find(edge[0]);
            componentCost[root]&=edge[2];
        }
        vector<int>ans;
        for(auto &q:query){
            int start = q[0];
            int end = q[1];
            if(find(start)!=find(end)){
                ans.push_back(-1);
            }else{
                int root = find(start);
                ans.push_back(componentCost[root]);
            }
        }
        return ans;
    }
};