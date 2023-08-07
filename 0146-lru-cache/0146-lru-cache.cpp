class LRUCache {
public:
    list<int> dll;
    map<int,pair<list<int>::iterator , int>> mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void mark_recently(int key){
        dll.erase(mp[key].first); // address erase kr diya
        dll.push_front(key);
        // ab map ko v update karo.....ab mp of key ka address change ho gya
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        
        // else
        mark_recently(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){ // if found already then just update the dll and update the key value 
            mark_recently(key);
            mp[key].second = value ;
        } 
        else{ // if not found then put it in the front and update mp and decrease the size as one filled
            dll.push_front(key);
            mp[key]={dll.begin() , value};
            n--;
        }
        
        if(n<0){
            // to meko bak se delte karna hoga
            int del = dll.back();
            mp.erase(del);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */