class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(),candies.end());
        vector<bool>result(candies.size(),false);
        for(int i=0;i<candies.size();i++){
            if(extraCandies+candies[i]>=maxi) result[i]=true;
        }
        return result;
    }
};