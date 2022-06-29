class Solution {
public:
    int longestPalindrome(string s) {
        int size = s.size();
        if (size == 0) return 0;
        if (size == 1) return 1;
        
        map<char, int> sOccurrences;
        for (auto& letter : s) {
            sOccurrences[letter]++;
        }
        
        int length = 0;
        bool oddExists = false;
        for (auto& entry : sOccurrences) {
            if (entry.second % 2) {
                oddExists = true;
                length += (entry.second - 1);
            } else {
                length += entry.second;
            }
        }
        
        return length + oddExists;
    }
};