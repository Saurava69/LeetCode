class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        sort(p.begin(),p.end());
        vector<vector<string>>ans;
        int n=s.size();
        int i=0;
        while(i<n){
            vector<string>temp;
            for(int j=0;j<p.size();j++)
            {
                if(s[i]==p[j][i])
                {
                    temp.push_back(p[j]);
                }
                
            }
            ans.push_back(temp);
            p=temp;
            i++;
        }
        vector<vector<string>>ans1;
        for(auto prod: ans)
        {
            vector<string>temp;
            for(int i=0;i<prod.size() and i<3 ;i++ )
            {
                temp.push_back(prod[i]);
            }
            ans1.push_back(temp);
        }
        return ans1;   
    }
};