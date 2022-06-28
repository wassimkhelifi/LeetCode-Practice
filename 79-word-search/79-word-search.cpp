class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == word.front() && wordExists(board, row, col, 0, word)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool wordExists(vector<vector<char>>& grid, int row, int col, int index, string word) {
        if (index == word.size()) return true;
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != word[index]) {
            return false;
        }
        
        char backtrackCopy = grid[row][col];
        grid[row][col] = ' ';
        bool exists =
            wordExists(grid, row + 1, col, index + 1, word) ||
            wordExists(grid, row - 1, col, index + 1, word) ||
            wordExists(grid, row, col + 1, index + 1, word) ||
            wordExists(grid, row, col - 1, index + 1, word);
        grid[row][col] = backtrackCopy;
        return exists;
    }
};