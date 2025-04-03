class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& entry : taskCount) {
            maxHeap.push(entry.second);
        }

        int time = 0;
        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1; // number of slots in a cycle
            for (int i = 0; i < cycle && !maxHeap.empty(); i++) {
                temp.push_back(maxHeap.top() - 1);
                maxHeap.pop();
            }

            for (int count : temp) {
                if (count > 0) {
                    maxHeap.push(count);
                }
            }

            time += maxHeap.empty() ? temp.size() : cycle;
        }

        return time;
    }
};