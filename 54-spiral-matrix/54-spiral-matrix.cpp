class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        while (matrix.size()) {
            for (int i = 0; i < matrix.size(); i++) {
                vector<int>& row = matrix[i];
                if (i == 0) {
                    spiral.insert(spiral.end(), row.begin(), row.end());
                } else if (i == matrix.size() - 1) {
                    reverse(row.begin(), row.end());
                    spiral.insert(spiral.end(), row.begin(), row.end());
                } else {
                    spiral.push_back(row.back());
                    row.pop_back();
                }
            }
            
            if (!matrix.empty()) {
                matrix.erase(matrix.begin());
            }
            
            if (!matrix.empty()) {
                matrix.pop_back();
            }
            
            if (!matrix.empty()) {
                for (int i = 0; i < matrix.size(); i++) {
                    if (matrix[i].empty()) {
                        matrix.erase(matrix.begin() + i);
                        i--;
                    }
                }
            }
            
            if (!matrix.empty()) {
                for (int i = matrix.size() - 1; i >= 0; i--) {
                    vector<int>& row = matrix[i];
                    spiral.push_back(row.front());
                    row.erase(row.begin());
                }
            }
            
            if (!matrix.empty()) {
                for (int i = 0; i < matrix.size(); i++) {
                    if (matrix[i].empty()) {
                        matrix.erase(matrix.begin() + i);
                        i--;
                    }
                }
            }
        }
        
        return spiral;
    }
};