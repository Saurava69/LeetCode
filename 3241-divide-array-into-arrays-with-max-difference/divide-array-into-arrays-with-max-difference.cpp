class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp;
        temp = nums;
        sort(temp.begin(),temp.end());
        vector<vector<int>>ans(n/3,vector<int>(3,0));
        int x=0;
        while(x<n){
            if(x+2<n and (temp[x+2]-temp[x])>k) return {};
            x+=3;
        }
        for(int i=0;i<n/3;i++){
            for(int j=0;j<3;j++){
                ans[i][j] = temp[i*3+j];
            }
        }
        return ans;
    }
};