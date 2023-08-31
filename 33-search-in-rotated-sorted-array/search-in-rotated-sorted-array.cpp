class Solution {
public:
    int search(vector<int>& arr, int k) {
         int n=arr.size();
        // int lo=0,hi=n-1;
        // // find the index of the smallest value using binary search.
        // // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        // while(lo<hi){
        //     int mid=(lo+hi)/2;
        //     if(A[mid]>A[hi]) lo=mid+1;
        //     else hi=mid;
        // }
        // // lo==hi is the index of the smallest value and also the number of places rotated.
        // int rot=lo;
        // lo=0;hi=n-1;
        // // The usual binary search and accounting for rotation.
        // while(lo<=hi){
        //     int mid=(lo+hi)/2;
        //     int realmid=(mid+rot)%n;
        //     if(A[realmid]==target)return realmid;
        //     if(A[realmid]<target)lo=mid+1;
        //     else hi=mid-1;
        // }
        // return -1;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;

    }
};