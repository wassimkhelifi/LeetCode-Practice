class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int freshOranges = 0;
        queue<pair<int, int>> traversalQueue;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) freshOranges++;
                else if (grid[i][j] == 2) traversalQueue.push(make_pair(i, j));
            }
        }
        
        if (!freshOranges) return 0;
        
        int minutes = -1;
        int numRows = grid.size();
        int numCols = grid[0].size();
        while (!traversalQueue.empty()) {
            minutes++;
            queue<pair<int, int>> adjacentOranges;
            while (!traversalQueue.empty()) {
                int row = traversalQueue.front().first;
                int col = traversalQueue.front().second;
                traversalQueue.pop();
                
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    freshOranges--;
                    adjacentOranges.push(make_pair(row - 1, col));
                }
                if (row + 1 < numRows && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    freshOranges--;
                    adjacentOranges.push(make_pair(row + 1, col));
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    freshOranges--;
                    adjacentOranges.push(make_pair(row, col - 1));
                }
                if (col + 1 < numCols && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    freshOranges--;
                    adjacentOranges.push(make_pair(row, col + 1));
                }
            }
            
            traversalQueue = adjacentOranges;
        }
        
        if (freshOranges) return -1;
        else return minutes;
    }
};