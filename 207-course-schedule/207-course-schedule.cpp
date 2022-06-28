class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0 || numCourses == 1) return true;
        
        map<int, vector<int>> adjacent;
        for (auto& prerequisite : prerequisites) {
            adjacent[prerequisite[0]].push_back(prerequisite[1]);
        }
        
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, visited, adjacent)) return false;
        }
        
        return true;
    }
    
    bool hasCycle(int course, vector<int>& visited, map<int, vector<int>>& adjacent) {
        if (visited[course] == 1) return true;
        else if (visited[course] == 0) {
            visited[course]++;
            for (auto& adjacentCourse : adjacent[course]) {
                if (hasCycle(adjacentCourse, visited, adjacent)) return true;
            }
        }
        
        visited[course]++;
        return false;
    }
};