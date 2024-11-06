class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n = word.length();
        int curr =1;
        for(int i=1;i<n;i++){
            if(word[i-1] == word[i] and curr <9){
                curr++;
            }
            else if(curr==9 or word[i]!=word[i-1]){
                ans.push_back(char(curr+48));
                ans.push_back(word[i-1]);
                curr =1;
            }
        }
        ans.push_back(char(curr+48));
        ans.push_back(word[n-1]);
        return ans;
    }   
};