class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &ch : s) {
            if (ch == '(' or ch == '{' or ch == '[') {
                st.push(ch);
            } 
            else if (st.empty()) return false; // If stack is empty, invalid case
            else if ((ch == ')' && st.top() == '(') || 
                     (ch == '}' && st.top() == '{') || 
                     (ch == ']' && st.top() == '[')) {
                st.pop(); // Correctly matched bracket, pop the stack
            } 
            else return false; // Mismatched bracket case
        }
        return st.empty(); // Stack should be empty if all pairs are matched
    }
};
