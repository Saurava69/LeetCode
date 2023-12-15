class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>countCity;
        for(auto &path: paths)
        {
            countCity[path[0]]++;
            countCity[path[1]]++;
        }
        vector<string>temp;
        for(auto &it:countCity)
        {
            if(it.second==1) temp.push_back(it.first);
        }
        for(auto &path:paths)
        {
            if(temp[0]==path[1]) return temp[0];
        }
        return temp[1];
    }
};