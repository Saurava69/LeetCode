class Solution {
public:
    bool isOperator(string &ch){
        return ch=="+" or ch=="-" or ch=="*" or ch=="/";
    }
    int calculateNewResult(int x, int y, string op){
        if(op=="+") return x+y;
        else if(op == "-") return y-x;
        else if(op == "*") return y*x;
        else{
            if(!x) return -1;
            return y/x;
        } 
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size(), i=0;
        while(i<n){
            if(isOperator(tokens[i])){
                if(!st.empty() and st.size()>=2){
                    int w1 = st.top(); st.pop();
                    int w2 = st.top(); st.pop();
                    //new result
                    int newResult =  calculateNewResult(w1,w2,tokens[i]);
                    st.push(newResult);
                    
                }
                else{
                    return -1;
                }
            }else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.empty()?-1:st.top();

    }
};