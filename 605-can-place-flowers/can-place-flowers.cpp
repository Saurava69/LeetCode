class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans =0;
        int n1 = flowerbed.size();
        if(n1==1 and flowerbed[0]==0) return true;  
        for(int i=0;i<n1;i++){
            if(i==0 and flowerbed[i] == 0 and i+1<n1 and flowerbed[i+1]!=1 ){
                ans++;
                flowerbed[i]=1;
            }
            else if(i==n1-1 and flowerbed[i] == 0 and i-1>=0 and flowerbed[i-1]!=1 ){
                ans++;
                flowerbed[i]=1;
            }
            else if(flowerbed[i] == 0 and i-1>=0 and flowerbed[i-1] != 1 and i+1<n1 and flowerbed[i+1] !=1) {
                ans++;
                flowerbed[i]=1;
            }
        }
        return ans>=n;
    }
};