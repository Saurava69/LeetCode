class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        long long sum=0;
        int prev=0;
        for(int i=1;i<colors.length();i++)
        {
            if(colors[i]==colors[prev])
            {
                if(neededTime[i]>neededTime[prev]){
                    sum+=neededTime[prev];
                    prev=i;
                }else
                { 
                    sum+=neededTime[i];
                }
            }else
                prev=i;
        }
        return sum;
    }
};