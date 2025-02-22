class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long total = 0;

        vector<int> stack;
        vector<long long> sdp(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++) {
            while (!stack.empty() && arr[stack.back()] > arr[i]) {
                stack.pop_back();
            }

            if (stack.empty()) {
                sdp[i] = (long long)(i + 1) * arr[i];
            } else {
                sdp[i] = sdp[stack.back()] + (long long)(i - stack.back()) * arr[i];
            }

            stack.push_back(i);
        }

        stack.clear();
        vector<long long> ldp(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++) {
            while (!stack.empty() && arr[i] > arr[stack.back()]) {
                stack.pop_back();
            }

            if (stack.empty()) {
                ldp[i] = (long long)(i + 1) * arr[i];
            } else {
                ldp[i] = ldp[stack.back()] + (long long)(i - stack.back()) * arr[i];
            }

            stack.push_back(i);
        }

        for (int i = 0; i < arr.size(); i++) {
            total += ldp[i] - sdp[i];
        }

        return total;
    }
};