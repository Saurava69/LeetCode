
class Solution {
public:
    struct State {
        int cover, head;
        State(int c=0, int h=0): cover(c), head(h) {}
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        queue<State> q;
        vector<vector<int>> dist(N, vector<int>(1<<N, INT_MAX));

        for (int x = 0; x < N; ++x) {
            q.push(State(1<<x, x));
            dist[x][1<<x] = 0;
        }

        while(!q.empty()){
            State node = q.front();
            q.pop();
            int d = dist[node.head][node.cover];
            if(node.cover==(1<<N)-1)
                return d; 

            for(int child: graph[node.head]){
                int cover2 = node.cover | (1<<child);
                if(d+1<dist[child][cover2]){
                    dist[child][cover2] = d+1;
                    q.push(State(cover2, child));
                }
            }
        }
        return -1;
    }
};