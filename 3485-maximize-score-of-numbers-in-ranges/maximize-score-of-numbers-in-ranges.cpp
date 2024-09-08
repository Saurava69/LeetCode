class Solution {
public:
    bool f(long long mid,vector<int>&nums,long long d){
         
        int n=nums.size();

        vector<long long>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=nums[i]*1LL+d;
        }          
        for(int i=n-1;i>=1;i--){
            if((temp[i]-temp[i-1])<mid){
                temp[i-1]=temp[i]-mid;
            }            
        }
        int check=1;
        for(int i=0;i<n;i++){
            if(temp[i]>=nums[i]&&temp[i]<=nums[i]+d)continue;
            else {check=0;break;}
        }
        return check;
         
    }
    int maxPossibleScore(vector<int>& nums, int d) {  
        int n=nums.size();       
        sort(nums.begin(),nums.end()); 
        int ans=0;
        int start=0;
        int end=2e9;       
        while(start<=end){
            int mid=start+(end-start)/2;
            int check=f(mid,nums,d);
            if(check){
                ans=mid;
                start=mid+1;
            }
            else end=mid-1;
        }
        return ans; 
    }
};