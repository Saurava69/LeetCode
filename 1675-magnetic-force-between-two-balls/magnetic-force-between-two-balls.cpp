class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //minimum magnetic force can be 1 and max up to max(pos)-min(pos)
        sort(position.begin(),position.end());
        int start,end,n=position.size(),count=1,ans;;
        start=1;
        end=position[n-1]-position[0];
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int pos=position[0],count=1;
            for(int i=1;i<n;i++)
            {
                if(pos+mid<=position[i])
                {
                    count++;
                    pos=position[i];
                }
            }
            if(count<m)
            {
                end=mid-1;
            }
            else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};