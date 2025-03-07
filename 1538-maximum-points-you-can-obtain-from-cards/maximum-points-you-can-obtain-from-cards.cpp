class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int j=cardPoints.size()-1;
        int maxSum = 0,currSum=0;
        for(int i=0;i<k;i++){
            currSum+=cardPoints[i];
            maxSum=max(maxSum,currSum);
        }
        for(int i=k-1;i>=0;i--){
            currSum-=cardPoints[i];
            currSum+=cardPoints[j];
            j--;
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};
