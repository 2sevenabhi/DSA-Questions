class LRUCache {
public:
    queue<int> history;
    unordered_map<int,int> memory;
    unordered_map<int,int> dup;
    int n;

    LRUCache(int capacity) {n = capacity;}
    
    int get(int key) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(memory.find(key) == memory.end()){return -1;}
        dup[key] ++;
        history.push(key);
        return memory[key];
    }
    
    void put(int key, int value) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if(memory.find(key) != memory.end()){
            memory[key] = value;
            dup[key] ++;
        }
        else if(n > 0){
            memory[key] = value;
            n --;
        }
        else{
            while(dup[history.front()] > 0){
                dup[history.front()] --;
                history.pop();
            }
            memory.erase(history.front());
            history.pop();
            memory[key] = value;
        }
        history.push(key);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */