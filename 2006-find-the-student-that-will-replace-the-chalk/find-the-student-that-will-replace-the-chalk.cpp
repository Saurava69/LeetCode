class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        int remain = k % sum;
        cout<<remain<<" ";
        int i =0;
        while(remain>0){
            remain-=chalk[i];
            if(remain < 0) return i;
            i++;
            cout<<remain<<" ";
        }
        return i;
    }
};