//https://leetcode.com/problems/domino-and-tromino-tiling/solutions/116581/detail-and-explanation-of-o-n-solution-why-dp-n-2-d-n-1-dp-n-3
class Solution {
public:
int numTilings(int N) {
    int md=1e9;
    md+=7;
    vector<long long> v(1001,0);
    v[1]=1;
    v[2]=2;
    v[3]=5;
    if(N<=3)
        return v[N];
    for(int i=4;i<=N;++i){
        v[i]=2*v[i-1]+v[i-3]; 
        v[i]%=md;
    }
    return v[N];
    
}
};