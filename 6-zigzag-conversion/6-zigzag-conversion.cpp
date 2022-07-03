class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (size == 1 || numRows == 1) return s;
        
        int row = 0;
        map<int, vector<char>> rowToLetters;
        bool ascending = true;
        for (auto& letter : s) {
            rowToLetters[row].push_back(letter);
            if (row == 0) {
                ascending = true;
                row++;
            } else if (0 < row && row < numRows - 1) {
                if (ascending) row++;
                else row--;
            } else if (row == numRows - 1){
                ascending = false;
                row--;
            }
        }
        
        string result;
        for (auto& entry : rowToLetters) {
            for (auto& letter : entry.second) {
                result += letter;
            }
        }
        
        return result;
    }
};