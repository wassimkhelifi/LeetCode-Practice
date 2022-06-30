class Trie {
    bool isLeaf = false;
    vector<Trie*> leaves = vector<Trie*>(26, NULL);
public:
    Trie() {}
    
    void insert(string word) {
        Trie* current = this;
        for (auto& letter : word) {
            int letterIndex = (int)letter - 97;
            if (!(current -> leaves[letterIndex])) {
                current -> leaves[letterIndex] = new Trie();
            }
            current = current -> leaves[letterIndex];
        }
        
        current -> isLeaf = true;
    }
    
    bool search(string word) {
        Trie* current = this;
        for (auto& letter : word) {
            int letterIndex = (int)letter - 97;
            if (!(current -> leaves[letterIndex])) return false;
            current = current -> leaves[letterIndex];
        }
        
        return current -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie* current = this;
        for (auto& letter : prefix) {
            int letterIndex = (int)letter - 97;
            if (!(current -> leaves[letterIndex])) return false;
            current = current -> leaves[letterIndex];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */