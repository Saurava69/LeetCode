class Solution {
public:
//     int jump(vector<int>& nums) {
// 	vector<int> dp(size(nums), 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
// 	return solve(nums, dp, 0);
// }
// // recursive solver to find min jumps to reach end
// int solve(vector<int>& nums, vector<int>& dp, int pos) {
// 	if(pos >= size(nums) - 1) return 0;    // when we reach end, return 0 denoting no more jumps required
// 	if(dp[pos] != 10001) return dp[pos];    // number of jumps from pos to end is already calculated, so just return it
// 	// explore all possible jump sizes from current position. Store & return min jumps required
// 	for(int j = 1; j <= nums[pos]; j++)
// 		dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));        
// 	return dp[pos];
// }
int jump(vector<int>& A) {
	int n=A.size();
	 if(n<2)return 0;
	 int level=0,currentMax=0,i=0,nextMax=0;

	 while(currentMax-i+1>0){		//nodes count of current level>0
		 level++;
		 for(;i<=currentMax;i++){	//traverse current level , and update the max reach of next level
			nextMax=max(nextMax,A[i]+i);
			if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level 
		 }
		 currentMax=nextMax;
	 }
	 return 0;
 }
};