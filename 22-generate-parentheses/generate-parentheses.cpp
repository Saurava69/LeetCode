class Solution {
public:
    vector<string>ans;

    void util(int o,int c,string temp)
    {
        if(o==0 && c==0)
        {
            ans.push_back(temp);
            return;
        }

        if(o!=0)
            util(o-1,c,temp+'(');

        if(o<c)
            util(o,c-1,temp+')');

    }
    vector<string> generateParenthesis(int n) {
        util(n,n,"");
        return ans;
    }
};