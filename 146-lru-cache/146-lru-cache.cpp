class Node {
public:
    int key;
    int val;
    Node* previous;
    Node* next;
    
    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
        previous = NULL;
        next = NULL;
    }
};

class LRUCache {
    map<int, Node*> cache;
    Node* LRU;
    Node* MRU;
    int capacity;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        LRU = new Node(-1, -1);
        MRU = new Node(-1, -1);
        LRU -> next = MRU;
        MRU -> previous = LRU;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key] -> val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(cache[key]);
        
        if (cache.size() > capacity) {
            Node* leastRecentlyUsed = LRU -> next;
            remove(leastRecentlyUsed);
            cache.erase(leastRecentlyUsed -> key);
        }
    }
    
    void insert(Node* node) {
        Node* previous = MRU -> previous;
        Node* next = MRU;
        previous -> next = node;
        node -> previous = previous;
        node -> next = MRU;
        MRU -> previous = node;
    }
    
    void remove(Node* node) {
        Node* previous = node -> previous;
        Node* next = node -> next;
        previous -> next = next;
        next -> previous = previous;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */