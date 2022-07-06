class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1) return true;
        
        map<int, vector<int>> adjacent;
        for (auto& prerequisite : prerequisites) {
            adjacent[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, adjacent, visited)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool hasCycle(int course, map<int, vector<int>>& adjacent, vector<int>& visited) {
        if (visited[course] == 1) return true;
        else if (visited[course] == 0) {
            visited[course]++;
            for (auto& adjacentCourse : adjacent[course]) {
                if (hasCycle(adjacentCourse, adjacent, visited)) {
                    return true;
                }
            }
        }
        
        visited[course]++;
        return false;
    }
};