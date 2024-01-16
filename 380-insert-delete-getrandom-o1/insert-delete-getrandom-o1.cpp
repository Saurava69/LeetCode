class RandomizedSet {
    unordered_map<long long,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)==mp.end())
        {
            mp[val]++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end())
        {
            if(mp[val]>1) mp[val]-=1;
            else mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int N=mp.size();
        int y= rand()%N;
        auto it=next(mp.begin(),y);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */