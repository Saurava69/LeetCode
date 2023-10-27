class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        int lis[n]; 

	lis[0] = 1; 
    int maxi=lis[0];
	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] < lis[j] + 1) 
				lis[i] = lis[j] + 1; 
    maxi=max(maxi,lis[i]);
	}
    return maxi; 
    }
};
// class Solution {
// public:
//     int n;
//     int t[2501][2501];
//     int lis(vector<int>& nums, int prev_idx, int curr_idx) {
//        if(curr_idx == n)
//            return 0;
        
//         if( t[prev_idx+1][curr_idx] != -1)
//             return t[prev_idx+1][curr_idx];

//         int not_taken = lis(nums, prev_idx, curr_idx+1);
//         int taken = 0;
//         if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx])
//             taken = 1 + lis(nums, curr_idx, curr_idx+1);
//         return t[prev_idx+1][curr_idx] =  max(taken, not_taken);
            
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         memset(t, -1, sizeof(t));
//         n = nums.size();
//         return lis(nums, -1, 0);
//     }
// };