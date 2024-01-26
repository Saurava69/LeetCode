class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int oldcolor=image[sr][sc];
        image[sr][sc]=color;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(q.size()!=0)
        {
            int k=q.size();
            while(k--)
            {
                auto [x, y] = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx >= 0 && ny >= 0 and nx < m && ny < n && image[nx][ny] == oldcolor && image[nx][ny] != color) {
                        image[nx][ny] = color;
                        q.push({nx, ny});
                    }                   
                }
            }
        }
        return image;
    }
};