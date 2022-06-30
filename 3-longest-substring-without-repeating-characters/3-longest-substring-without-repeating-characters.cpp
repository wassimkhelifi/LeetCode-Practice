class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        
        int length = 0;
        queue<char> longestSubstring;
        unordered_set<char> visited;
        for (auto& letter : s) {
            if (visited.count(letter)) {
                while (longestSubstring.front() != letter) {
                    visited.erase(longestSubstring.front());
                    longestSubstring.pop();
                }
                
                longestSubstring.pop();
                visited.erase(letter);
            }
            
            longestSubstring.push(letter);
            visited.insert(letter);
            length = max(length, (int)longestSubstring.size());
        }
        
        return length;
    }
};