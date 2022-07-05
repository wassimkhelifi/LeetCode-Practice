class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 1) return s;
        
        vector<vector<bool>> memo(size, vector<bool>(size, false));
        for (int i = 0; i < size; i++) {
            memo[i][i] = true;
        }
        
        string longest;
        longest += s.front();
        for (int right = 1; right < s.size(); right++) {
            for (int left = right - 1; left >= 0; left--) {
                if (s[left] == s[right]) {
                    if (memo[left + 1][right - 1] or right - left == 1) {
                        memo[left][right] = true;
                        if (right - left + 1 > longest.size()) {
                            longest = s.substr(left, right - left + 1);
                        }
                    }
                }
            }
        }
        
        return longest;
    }
};