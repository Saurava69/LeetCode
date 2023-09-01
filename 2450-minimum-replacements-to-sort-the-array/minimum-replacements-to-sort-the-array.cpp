class Solution {
    public: long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        
        long operations = 0;

        for (int i = n - 2; i >= 0; i--) {
            
            if (nums[i] <= nums[i + 1]) {
                continue;
            }

            long parts = (long)(nums[i]) / (long)nums[i + 1];
            
            if(nums[i] % nums[i+1] != 0)
                parts += 1;

            operations += parts - 1;

            nums[i] = nums[i] / (int)parts;
        }

        return operations;
    }
};

// class Solution {
// public:
//     long long minimumReplacement(vector<int>& nums) {
//         int n = nums.size();
//         long long result = 0;
        
//         for(int i = n-2; i >= 0; i--) {

//             int splits = nums[i]/nums[i+1];
            
//             if((nums[i]) % nums[i+1] != 0) {
//                 splits++;
//             }
            
//             nums[i] = nums[i]/splits;
//             result += splits-1;
//         }
        
//         return result;
//     }
// };