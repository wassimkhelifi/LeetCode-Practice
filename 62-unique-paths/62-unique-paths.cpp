class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n));
        for (int col = 0; col < n; col++) {
            memo[0][col] = 1;
        }
        for (int row = 0; row < m; row++) {
            memo[row][0] = 1;
        }
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                memo[row][col] = memo[row - 1][col] + memo[row][col - 1];
            }
        }
        
        return memo[m - 1][n - 1];
    }
};