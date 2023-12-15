class Solution {
public: 
int firstMissingPositive(vector<int>&arr)
{
    // Write your code here.
    int n=arr.size();
   unordered_set<int>st;
   for(int i=0;i<n;i++)
   {
       st.insert(arr[i]);
   }
   for(int i=1;i<=n+1;i++)
   {
       if(st.find(i)==st.end()) return i;
   }
   return -1;
}
};