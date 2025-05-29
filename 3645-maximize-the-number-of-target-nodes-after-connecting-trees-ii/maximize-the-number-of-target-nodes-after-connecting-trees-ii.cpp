class Solution {
public: 
    void buildGraph(vector<vector<int>>& edges1,vector<vector<int>>&adj1){
        for(auto &edge:edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
    }
    void dfs(int node,int parent,int parity,vector<int>&p1,vector<vector<int>>&adj1){
        p1[node]=parity;
        for(auto &ngbr:adj1[node]){
            if(ngbr!=parent){
                dfs(ngbr,node,(1-parity),p1,adj1);
            }
        }
        return;

    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        buildGraph(edges1,adj1);
        buildGraph(edges2,adj2);
        vector<int>p1(n),p2(m);
        dfs(0,-1,0,p1,adj1);
        dfs(0,-1,0,p2,adj2);
        // for(auto x:p1) cout<<x<<" "; cout<<endl;
        // for(auto x:p2) cout<<x<<" ";
        int even=0,odd=0;
        for(int &x:p2){
            if(x==0) even++;
            else odd++;
        }
        cout<<even<<" "<<odd<<" ";
        int maxNode = max(even,odd);
        vector<int>ans(n);
        even = 0,odd=0;
        for(int &x:p1){
            if(x==0) even++;
            else odd++;
        }
        cout<<even<<" "<<odd<<" ";
        for(int i=0;i<n;i++){
            if(p1[i]==0){
                ans[i] = even+maxNode;
            }else 
                ans[i] = odd+maxNode;
        }
        return ans;
    }
};