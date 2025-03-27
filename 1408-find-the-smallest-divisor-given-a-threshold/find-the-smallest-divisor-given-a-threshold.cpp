class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=h;
        auto check = [&](int mid){
            int temp=0;
            for(auto &x:nums){
                temp+=ceil(float(x)/float(mid));
            }
            return temp<=threshold;
        };
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};