class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,sell,profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i]<buy)
            {
                buy=prices[i];
            }
            sell=prices[i]-buy;
            if(sell>profit) profit=sell;
        }
        return profit;
    }
};