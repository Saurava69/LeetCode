class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    //     vector<vector<int>>row(grid.size(), vector<int> (grid[0].size()));
        
    //     for(int i=0;i<grid.size();i++)
    //     {
    //         for(int j=0;j< grid[i].size();j++)
    //         {
    //             int temp0=0;
    //             int temp1=0;
    //             row[i][j]=0;
    //             for(int k=0;k<grid[i].size();k++)
    //             {
    //                 if(grid[i][k]==0) temp0++;
    //                 else temp1++;
    //             }
    //             row[i][j]=temp1-temp0;
    //             temp1=0;
    //             temp0=0;
    //             for(int k=0;k<grid.size();k++)
    //             {
    //                 if(grid[k][j]==0) temp0++;
    //                 else temp1++;
    //             }
    //             row[i][j]+=(temp1-temp0);
    //         }
    //     }
    //     return row;
    // }
    const int m = grid.size();
    const int n = grid[0].size();
    vector<int>row(m,0);
    vector<int>col(n,0);
    vector<vector<int>> ansGrid(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1){ 
                ++row[i];
                ++col[j];
            }else 
            {
                --row[i];
                --col[j];
            }
            
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ansGrid[i][j]=row[i]+col[j];
        }
    }
    return ansGrid;
    }
    
};