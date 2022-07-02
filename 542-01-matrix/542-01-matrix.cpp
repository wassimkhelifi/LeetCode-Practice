class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int numRows = mat.size();
        int numCols = mat[0].size();
        
        queue<pair<int, int>> traversalQueue;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (mat[row][col] == 1) {
                    mat[row][col] = -1;
                } else {
                    traversalQueue.push(make_pair(row, col));
                }
            }
        }
        
        while (!traversalQueue.empty()) {
            int row = traversalQueue.front().first;
            int col = traversalQueue.front().second;
            traversalQueue.pop();
            int distance = mat[row][col] + 1;
            
            if (row - 1 >= 0 && mat[row - 1][col] == -1) {
                mat[row - 1][col] = distance;
                traversalQueue.push(make_pair(row - 1, col));
            }
            if (row + 1 < numRows && mat[row + 1][col] == -1) {
                mat[row + 1][col] = distance;
                traversalQueue.push(make_pair(row + 1, col));
            }
            if (col - 1 >= 0 && mat[row][col - 1] == -1) {
                mat[row][col - 1] = distance;
                traversalQueue.push(make_pair(row, col - 1));
            }
            if (col + 1 < numCols && mat[row][col + 1] == -1) {
                mat[row][col + 1] = distance;
                traversalQueue.push(make_pair(row, col + 1));
            }
        }
        
        return mat;
    }
};