class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
            if(sum > k) break;
        }
        k = k % sum;
        
        int i =0;
        while(k>0){
            k-=chalk[i];
            if(k < 0) return i;
            i++;
        }
        return i;
    }
};