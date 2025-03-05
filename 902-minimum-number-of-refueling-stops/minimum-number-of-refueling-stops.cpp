class Solution {
public:
    // Method to find the minimum number of refueling stops required
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max heap to store the fuel available at the stations
        priority_queue<int> fuelMaxHeap; 
      
        // Add a final station at the target position with 0 fuel
        stations.push_back({target, 0});
      
        // Initialize answer (minimum refueling stops) and previous station
        int minStops = 0, prevStationDist = 0;
      
        // Iterate through the stations along the route
        for (auto& station : stations) {
            // Calculate the distance to the current station from the previous station
            int distance = station[0] - prevStationDist;
          
            // Reduce the start fuel by the distance traveled
            startFuel -= distance;
          
            // While the fuel is not enough to reach the next station and there's fuel in the max heap, refuel
            while (startFuel < 0 && !fuelMaxHeap.empty()) {
                // Add the max fuel available from passed stations
                startFuel += fuelMaxHeap.top();
                fuelMaxHeap.pop();
              
                // Increment the minimum stops as we've refueled
                ++minStops;
            }
          
            // If the fuel is still not enough, return -1 indicating it is not possible
            if (startFuel < 0) {
                return -1;
            }
          
            // Add the current station's fuel to the max heap
            fuelMaxHeap.push(station[1]);
          
            // Update the previous station distance
            prevStationDist = station[0];
        }
      
        // Return the minimum number of stops to refuel
        return minStops;
    }
};