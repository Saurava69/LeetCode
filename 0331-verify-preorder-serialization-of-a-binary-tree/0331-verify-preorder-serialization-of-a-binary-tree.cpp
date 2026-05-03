class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string x;
        int diff = 1;
        while(getline(ss,x,',')){
            if(--diff<0) return false;
            if(x!="#") diff+=2;
        }
        return diff==0;

    }
};