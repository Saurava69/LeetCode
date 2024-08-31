class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n);
        prob[start_node] = 1.0;

        for(int i=0; i<n; i++){
            bool isConnected = false;
            for(int j=0; j<edges.size(); j++){
                int a = edges[j][0],b = edges[j][1];
                double p = succProb[j];

                if(prob[b] < prob[a]*p){
                    prob[b] = prob[a]*p;
                    isConnected = true;
                }

                if(prob[a] < prob[b]*p){
                    prob[a] = prob[b]*p;
                    isConnected = true;
                }
            }
            if(!isConnected) break;
        }
        return prob[end_node];
    }
};