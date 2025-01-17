class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for(auto &c:derived){
            sum^=c;
        }
        return sum == 0?1:0;
    }
};