class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int Max=INT_MIN;
        sort(points.begin(),points.end());
        for(int i=1;i<points.size();i++)
        {
            Max=max(Max,points[i][0]-points[i-1][0]);
        }
        return Max;
    }
};