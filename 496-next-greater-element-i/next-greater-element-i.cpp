class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;  // Map to store the next greater element for each number in nums2
        stack<int> st;  // Monotonic decreasing stack to track the next greater element

        // Iterate over nums2 from right to left (reverse order)
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller than or equal to nums2[i]
            while (!st.empty() && st.top() < nums2[i]) {
                st.pop();  // Remove smaller elements, they cannot be the NGE
            }

            // If stack is empty, there is no greater element to the right
            if (st.empty()) {
                ngeMap[nums2[i]] = -1;  // No NGE found, assign -1
            } else {
                ngeMap[nums2[i]] = st.top();  // Assign the top of the stack as NGE
            }

            // Push the current element onto the stack for future comparisons
            st.push(nums2[i]);
        }

        // Prepare the result for nums1 by looking up the values in ngeMap
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = ngeMap[nums1[i]];  // Retrieve precomputed NGE from the map
        }

        return result;  // Return the final result
    }
};