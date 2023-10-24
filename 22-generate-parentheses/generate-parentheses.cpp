class Solution {
public:
void helper(int i,int N,vector<string>&ans,string s,int o,int e)
{
    if(i==2*N){
        if(o==e)
            ans.push_back(s);
        return;
    }
    helper(i+1,N,ans,s+'(',o+1,e);
    if((i!=0 and o>e) )
        helper(i+1,N,ans,s+')',o,e+1);
    
}
vector<string> generateParenthesis(int N) {
    vector<string>ans;
    helper(0,N,ans,"",0,0);
    return ans;
    }
};