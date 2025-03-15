class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        //create min Heap
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, n = A.size(),d=0;
        while(i<n or !pq.empty()){
            if(pq.empty()) d = A[i][0];
            //insert into priority queue if event start day is less than or eequal to curray day
            while(i<n and A[i][0]<=d){
                pq.push(A[i++][1]);
            }
            pq.pop();
            d++;
            res++;
            //clear the events which canot able to make within d days
            while(!pq.empty() and pq.top()<d){
                pq.pop();
            }
        }
        return res;
    }
};