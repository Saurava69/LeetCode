class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto &ch:s){
            if(ch == '*'){
                if(ans!="")
                ans.pop_back();
            }
            else if(ch == '#'){
                ans+=ans;
            }else if(ch == '%'){
                reverse(ans.begin(),ans.end());
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};