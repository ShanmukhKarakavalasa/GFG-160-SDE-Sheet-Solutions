
class LRUCache {
  public:
    int capacity;
    list<pair<int, int>> l; 
    map<int, list<pair<int, int>>::iterator> mp;
    
    LRUCache(int cap) {
        this->capacity=cap;
    }

    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end()){
            return -1;
        }
        
        int val=it->second->second;
        l.erase(it->second);
        l.push_front({key, val});
        
        mp[key]=l.begin();
        return val;
    }

        
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            l.erase(it->second);
            mp.erase(it);
        }
        
        l.push_front({key, value});
        mp[key]=l.begin();
        
        if(mp.size()>capacity){
            auto last_node_key=l.back().first;
            l.pop_back();
            mp.erase(last_node_key);
        }
    }
};
