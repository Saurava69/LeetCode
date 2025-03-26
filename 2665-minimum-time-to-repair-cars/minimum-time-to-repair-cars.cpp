class Solution {
public:
    long repairCars(vector<int>& ranks, int cars) {
        priority_queue<tuple<long, int, long>, vector<tuple<long, int, long>>, greater<>> minHeap;

        // Add all mechanics to the heap
        for (int rank : ranks) {
            minHeap.push({rank, rank, 1}); // {time, rank, cars_repaired}
        }

        long time = 0;
        while (cars > 0) {
            auto [t, rank, n] = minHeap.top();
            minHeap.pop();

            time = t; // Current minimum time
            cars--;   // Repair one car

            // Push the updated time back into the heap
            minHeap.push({rank * (n + 1) * (n + 1), rank, n + 1});
        }
        return time;
    }
};