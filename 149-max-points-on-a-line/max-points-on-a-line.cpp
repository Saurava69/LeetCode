class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int ans = 0;

        for(int i = 0; i < n; i++) {

            map<pair<int,int>, int> mp;

            int currMax = 0;

            for(int j = i + 1; j < n; j++) {

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];

                if(dx == 0) {
                    dy = 1;
                }
                else if(dy == 0) {
                    dx = 1;
                }
                else {

                    int g = gcd(abs(dx), abs(dy));

                    dx /= g;
                    dy /= g;

                    if(dx < 0) {
                        dx *= -1;
                        dy *= -1;
                    }
                }

                mp[{dy, dx}]++;

                currMax = max(currMax, mp[{dy, dx}]);
            }

            ans = max(ans, currMax + 1);
        }

        return ans;
    }
};