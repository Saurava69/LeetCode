class Solution {
public:
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;

        vector<int> map(26, 0);
        vector<bool> visited(26, false);
        string res;

        for (auto& ch : s) map[ch - 'a']++;
        for (auto& ch : s) {
            if (visited[ch - 'a']) {
                map[ch - 'a']--;
                continue;
            }

            while (!res.empty() && res.back() > ch && map[res.back() - 'a'] > 0) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            visited[ch - 'a'] = true;
            map[ch - 'a']--;
        }
        return res;
    }
};


// class Solution {
// public:
//     string temp;
//     vector<string> ans;
//     void solver(string &s,int currIndex,map<char,int> mp,int &totalUniqueElements){
        
//         if(currIndex >= s.size() && temp.size() == totalUniqueElements){
//             ans.push_back(temp);
//             return;
//         }
//         if(currIndex >= s.size()) return;
        
//         if(mp[s[currIndex]] > 1){
//             int value = mp[s[currIndex]];
//             temp.push_back(s[currIndex]);
//             mp[s[currIndex]] =0; 
            
//             solver(s,currIndex+1,mp,totalUniqueElements);
//             temp.pop_back();
//             mp[s[currIndex]] = value;
//             solver(s,currIndex+1,mp,totalUniqueElements);
//         }
//         else if(mp[s[currIndex]] == 1){
//             temp.push_back(s[currIndex]);
//             solver(s,currIndex+1,mp,totalUniqueElements);
//             temp.pop_back();
//         }
//         else if(mp[s[currIndex]] == 0){
//             solver(s,currIndex+1,mp,totalUniqueElements);
//         }
//         return;
//     }
    
//     string removeDuplicateLetters(string s) 
//     {
//         map<char,int> mp;
//         for(auto it: s){
//             mp[it]++;
//         }
//         int totalUniqueElements = mp.size();
//         solver(s,0,mp,totalUniqueElements);
//         sort(ans.begin(),ans.end());
//         return ans[0];
        
//     }
// };
