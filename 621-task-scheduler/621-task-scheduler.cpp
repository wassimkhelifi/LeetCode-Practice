class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> occurrences;
        for (auto& task : tasks) {
            occurrences[task]++;
        }
        
        priority_queue<int> maxHeap;
        for (auto& entry : occurrences) {
            maxHeap.push(entry.second);
        }
        
        int time = 0;
        queue<pair<int, int>> idleQueue;
        while (!maxHeap.empty() or !idleQueue.empty()) {
            time++;
            if (!maxHeap.empty()) {
                int task = maxHeap.top();
                maxHeap.pop();
                task--;
                if (task) {
                    idleQueue.push({task, time + n});
                }
            }
            
            if (!idleQueue.empty() and idleQueue.front().second == time) {
                maxHeap.push(idleQueue.front().first);
                idleQueue.pop();
            }
        }
        
        return time;
    }
};