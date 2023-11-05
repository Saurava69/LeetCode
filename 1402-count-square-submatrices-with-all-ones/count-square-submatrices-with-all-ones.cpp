class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                        matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                }
            }
        }
        int count=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                count+=matrix[i][j];
            }
        }
        return count;
    }
};