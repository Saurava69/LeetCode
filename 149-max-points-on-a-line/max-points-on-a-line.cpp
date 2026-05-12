class Solution {
public:
    double slope(vector<int>&point1, vector<int>&point2){
        int x1 = point1[0], x2 = point2[0], y1 = point1[1], y2 = point2[1];
        return (x2-x1) != 0 ? double(y2-y1)/(x2-x1) : INT_MAX;
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0, n = points.size();

        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++){
                if(i!=j){
                    double sl = slope(points[i],points[j]);
                    mp[sl]++;
                }
            }
            for(auto [x,y]:mp){
                ans = max(ans,y);
            }
        }
        return ans+1;
    }
};