class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1=g.size(),n2=s.size(),i=0,j=0;
        int ans=0;
        while(i<n1 and j<n2)
        {
            if(s[j]>=g[i])
            {
                i++;
                ans+=1;
            }
            j++;
        }
        return ans;
        
    }
};