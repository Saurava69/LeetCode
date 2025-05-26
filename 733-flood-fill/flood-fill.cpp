class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int c = image[sr][sc];
       // vector<vector<int>>visited=image;
        if( c==color) return image;
        image[sr][sc] = color;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            vector<pair<int,int>>dir = {{0,1},{0,-1},{-1,0},{1,0}};
            for(auto &[dx,dy]:dir){
                int u = x+dx, v = y + dy;
                if(u<n and u>=0 and v<m and v>=0 and image[u][v]==c){
                    image[u][v] = color;
                    q.push({u,v});
                }
            }
        }
        return image;
    }
};