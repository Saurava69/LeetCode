class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]){
        return a[0]<=b[0];
    }
    return a[1]<b[1];
}
    int maxEvents(vector<vector<int>>& A) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, n = A.size();
        for (int d = 1; d <= 100000; ++d) {
            while (pq.size() && pq.top() < d)
                pq.pop();
            while (i < n && A[i][0] == d)
                pq.push(A[i++][1]);
            if (pq.size()) {
                pq.pop();
                ++res;
            }
        }
        return res;
    }
};