class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0)); // dp[i][j] -> max distance with j stops up to i-th station
        
        // Base case: With 0 stops, we can reach only as far as startFuel allows
        dp[0][0] = startFuel;
        
        for (int i = 1; i <= n; i++) {
            int stationPos = stations[i - 1][0]; // Position of current station
            int stationFuel = stations[i - 1][1]; // Fuel available at this station
            
            for (int j = 0; j <= i; j++) {  
                // If we don't take fuel from this station
                dp[i][j] = dp[i - 1][j];
                
                // If we take fuel (only if we made at least one stop)
                if (j > 0 && dp[i - 1][j - 1] >= stationPos) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + stationFuel);
                }
            }
        }
        
        // Find the minimum stops required to reach target
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] >= target) return j;
        }
        
        return -1; // Target is unreachable
    }
};