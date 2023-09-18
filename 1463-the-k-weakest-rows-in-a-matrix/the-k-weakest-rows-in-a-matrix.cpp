class Solution {
public:
    static bool comp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.first==b.first) return a.second<b.second;

        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>count;
        vector<int>ans;
        for(int i=0;i<mat.size();i++)
        {
            int temp=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1) temp++;
            }
            count.push_back({temp,i});
        }
        sort(count.begin(),count.end(),comp);
        for(int i=0;i<k;i++)
            ans.push_back(count[i].second);
        
        return ans;
    }
};