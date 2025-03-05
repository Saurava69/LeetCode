class Solution {
public:
    // Method to find the minimum number of refueling stops required
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;

        int max_reach = startFuel;
        int count = 0;
        int n= stations.size();
        int i= 0;
        while(max_reach<target){
            while(i<n and stations[i][0]<=max_reach){
                pq.push( stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            max_reach+=pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};