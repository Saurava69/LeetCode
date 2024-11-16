class Solution {
public:
  
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int ans=0, n=days.size();
        queue<pair<int,int>> mon,week;
        for(int day:days)
        {
            while(mon.size()>0 &&mon.front().first+30<=day)
            {
                mon.pop();
            }
            while(week.size()>0 &&week.front().first+7<=day)
            {
                week.pop();
            } 
            mon.push({day,ans+cost[2]});
            week.push({day,ans+cost[1]});
            ans=min({ans+cost[0],mon.front().second,week.front().second}) ;
        }
        return ans;
    }
};