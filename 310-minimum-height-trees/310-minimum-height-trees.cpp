class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 0) return {};
        if (n == 1) return {0};
        
        map<int, vector<int>> adjacent;
        map<int, int> degree;
        for (auto& edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        queue<int> traversalQueue;
        for (auto& entry : degree) {
            if (entry.second == 1) {
                traversalQueue.push(entry.first);
            }
        }
        
        while (n > 2) {
            int size = traversalQueue.size();
            n -= size;
            while (size) {
                int currentNode = traversalQueue.front();
                traversalQueue.pop();
                degree[currentNode]--;
                for (auto& adjacentNode : adjacent[currentNode]) {
                    degree[adjacentNode]--;
                    if (degree[adjacentNode] == 1) {
                        traversalQueue.push(adjacentNode);
                    }
                }
                size--;
            }
        }
        
        vector<int> minimumHeightTrees;
        while (!traversalQueue.empty()) {
            minimumHeightTrees.push_back(traversalQueue.front());
            traversalQueue.pop();
        }
        
        return minimumHeightTrees;
    }
};