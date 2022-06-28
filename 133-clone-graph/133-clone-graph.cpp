/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        
        map<Node*, vector<Node*>> adjacent;
        queue<Node*> traversalQueue;
        traversalQueue.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        
        while (!traversalQueue.empty()) {
            Node* current = traversalQueue.front();
            traversalQueue.pop();
            adjacent[current] = current -> neighbors;
            for (auto& neighbor : current -> neighbors) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    traversalQueue.push(neighbor);
                }
            }
        }
        
        map<Node*, Node*> oldToNew;
        for (auto& entry : adjacent) oldToNew[entry.first] = new Node(entry.first -> val);
        
        for (auto& entry : adjacent) {
            Node* oldNode = entry.first;
            vector<Node*> oldNeighbors = entry.second;
            Node* newNode = oldToNew[oldNode];
            vector<Node*> newNeighbors;
            for (auto& oldNeighbor : oldNeighbors) newNeighbors.push_back(oldToNew[oldNeighbor]);
            newNode -> neighbors = newNeighbors;
        }
        
        return oldToNew.begin() -> second;
    }
};