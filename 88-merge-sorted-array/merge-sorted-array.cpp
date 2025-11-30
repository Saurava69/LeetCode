class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;         // last valid element in nums1
    int j = n - 1;         // last element in nums2
    int k = m + n - 1;     // fill nums1 from the end

    // Merge from back so we don't overwrite nums1's data
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Only nums2 may have leftover elements
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

};