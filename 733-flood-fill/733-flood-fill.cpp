class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] != color) {
            dfs(image, sr, sc, image[sr][sc], color);
        }
        return image;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, int oldColor, int newColor) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != oldColor) {
            return;
        }
        
        grid[row][col] = newColor;
        dfs(grid, row + 1, col, oldColor, newColor);
        dfs(grid, row - 1, col, oldColor, newColor);
        dfs(grid, row, col + 1, oldColor, newColor);
        dfs(grid, row, col - 1, oldColor, newColor);
    }
};