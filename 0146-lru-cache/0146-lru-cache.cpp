class LRUCache {
public:
    int time;
    int keyCnt;
    int limit;
    unordered_map<int,int> keyTime;//key,lastTime
    unordered_map<int,int> keyVal; //key, val pair
    LRUCache(int capacity) {
        this->time = 0;
        this->keyCnt = 0;
        this->limit = capacity;
    }
    
    int get(int key) {
        time++;
        if(keyVal.count(key)){
            keyTime[key] = time;
            return keyVal[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        time++;
        
        if(keyVal.count(key)){
            keyVal[key] = value;
            keyTime[key] = time;
        }
        else{
            if(keyCnt >= limit){
                int minTime = INT_MAX;
                int leastKey;
                for(auto &[k,v]: keyTime){
                    if(minTime > v){
                        minTime = v;
                        leastKey = k;
                    }
                }
                keyVal.erase(leastKey);
                keyTime.erase(leastKey);
            }
            keyCnt++;
            keyVal[key] = value;
            keyTime[key] = time;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */