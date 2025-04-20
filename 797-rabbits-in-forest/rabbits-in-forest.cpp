class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        sort(answers.begin(),answers.end());
        if(answers.size()==0) return 0;
        int i=0;
        while(i<answers.size()){
            int x = answers[i++];
            ans+=(x+1);
            int t = i+x;
            for(int j=i;j<answers.size() and j<t;j++){
                if(answers[j] == x) i++;
                else break;
            }
        }
        return ans;
    }
};