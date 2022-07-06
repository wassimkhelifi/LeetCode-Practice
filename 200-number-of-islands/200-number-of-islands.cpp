// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int numberOfIslands = 0;
//         for (int row = 0; row < grid.size(); row++) {
//             for (int col = 0; col < grid[row].size(); col++) {
//                 if (grid[row][col] == '1') {
//                     numberOfIslands++;
//                     dfs(grid, row, col);
//                 }
//             }
//         }
        
//         return numberOfIslands;
//     }
    
//     void dfs(vector<vector<char>>& grid, int row, int col) {
//         if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
//             return;
//         }
        
//         grid[row][col] == '0';
//         dfs(grid, row + 1, col);
//         dfs(grid, row - 1, col);
//         dfs(grid, row, col + 1);
//         dfs(grid, row, col - 1);
//     }
// };

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == '1') {
                    numberOfIslands++;
                    dfs(grid, row, col);
                }
            }
        }
        
        return numberOfIslands;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
            return;
        }
        
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
};
