// class Solution {
// public:
//     int minSteps(string s, string t) 
//     {
//         unordered_map<char,int>m;
//         int count = 0;

//         for(int i = 0; i<s.size(); i++)
//         {
//             m[s[i]]++;
//         }
//         for(int i = 0; i<t.size(); i++)
//         {
//             m[t[i]]--;
//         }
//         for(auto x : m)
//         {
//             count += abs(x.second);
//         }
//         return count/2;
//     }
// };

// Method 2

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt1(26,0);
        for(int i=0;i<s.length();i++)
        {
            cnt1[s[i]-'a']++;
            cnt1[t[i]-'a']--;
        }
        int sum=0;
        for(int i=0;i<26;i++)
            sum+=abs(cnt1[i]);

        return sum/2;
    }
};