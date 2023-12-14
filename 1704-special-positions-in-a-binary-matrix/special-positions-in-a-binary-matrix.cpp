class Solution {
public:
    int numSpecial(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int>row(m,0);
    vector<int>col(n,0);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1){ 
                ++row[i];
                ++col[j];
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1 and row[i]==1 and col[j]==1) ++ans;
        }
    }
    return ans;

    }
};