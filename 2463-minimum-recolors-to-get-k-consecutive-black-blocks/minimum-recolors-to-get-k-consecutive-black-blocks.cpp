class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int wc =0,minWc=k,n = blocks.length();
        for(int i=0;i<k;i++){
            if(blocks[i] == 'W'){
                wc++;
            }
        }
        minWc = min(minWc,wc);
        //cout<<minWc<<" "<<blocks[]<<" "<<blocks[i]<<" ";
        int i=0,j=k;

        while(j<n){
            if(blocks[j] == 'W'){
                if(blocks[i] != 'W') wc++;
                //cout<<wc<<" "<<minWc<<" "<<blocks[j]<<" "<<blocks[i]<<" ";
            }
            else if(blocks[j] == 'B'){
                if(blocks[i] == 'W') {
                    if(wc>0) wc--;
                }
                cout<<wc<<" "<<blocks[j]<<" "<<blocks[i]<<" ";
            }
            minWc = min(minWc,wc);
            i++;j++;
        }
        return minWc;
    }
};