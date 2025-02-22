class Solution {
public:
    void calcNGR(int n,vector<int>&height,  vector<int>&ngr){
        ngr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            ngr[i]= max(ngr[i+1],height[i]);
        }
    }
    void calcNGL(int n,vector<int>&height,  vector<int>&ngl){
        ngl[0] = height[0];
        for(int i=1;i<n;i++){
            ngl[i] = max(ngl[i-1],height[i]);
        }
    }

    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>ngr(n);
        vector<int>ngl(n);
        
        calcNGR(n,height,ngr);
        calcNGL(n,height,ngl);
        int ans = 0;
        for(int i=0;i<n;i++){
            int Min = min(ngr[i],ngl[i]);
            if(height[i]>=Min) continue;
            else{
                ans+=(Min-height[i]);
            }
        }
        return ans;
    }
};