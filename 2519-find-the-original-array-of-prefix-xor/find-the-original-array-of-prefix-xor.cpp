class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev=pref[0];
        for(int i=1;i<pref.size();i++)
        {
            int prev1=pref[i];
            pref[i]=pref[i]^prev;
            prev=prev1;
        }
        return pref;
    }
};