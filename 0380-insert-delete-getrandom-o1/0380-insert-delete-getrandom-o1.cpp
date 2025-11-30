class RandomizedSet {
public:
    unordered_map<int,int> store;
    vector<int> keys;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(store.count(val) == 0){
            keys.push_back(val);
            store[val] = keys.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(store.count(val)){
            int idx = store[val];
            int n = keys.size();

            int laste = keys[n-1];
            keys[idx] = laste;
            keys.pop_back();
            store[laste] = idx;
            store.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int randKey = keys[rand() % keys.size()];
        return randKey;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */