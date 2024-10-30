class MyHashMap {
    vector<list<pair<int,int>>> table;
    int size = 769; 
public:
    MyHashMap() {
        table.resize(size);
    }

    int hashFunction(int key){
        return (key % size);
    }
    
    void put(int key, int value) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for(auto &curr : chain){
            if(curr.first == key) {
                curr.second = value;
                return;
            }
        }
        chain.push_back({key,value});
        return;
    }
    
    int get(int key) {
        int index = hashFunction(key);
       auto& chain = table[index];
        for(auto &curr : chain){
            if(curr.first == key) {
                return curr.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
       auto& chain = table[index];
        for(auto curr : chain){
            if(curr.first == key) {
                chain.remove(curr);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */