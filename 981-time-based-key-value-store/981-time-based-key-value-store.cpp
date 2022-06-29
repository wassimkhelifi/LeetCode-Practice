class TimeMap {
    map<string, map<int, string>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (store[key].count(timestamp)) {
            return store[key][timestamp];
        } else {
            for (int i = timestamp - 1; i >= 0; i--) {
                if (store[key].count(i)) {
                    return store[key][i];
                }
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */