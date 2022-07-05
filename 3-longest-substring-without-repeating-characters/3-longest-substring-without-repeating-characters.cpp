class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        
        if (size == 0) return 0;
        if (size == 1) return 1;
        
        int longestLength = 0;
        unordered_set<char> seen;
        queue<char> longestSubstring;
        for (auto& letter : s) {
            if (seen.count(letter)) {
                while (longestSubstring.front() != letter) {
                    seen.erase(longestSubstring.front());
                    longestSubstring.pop();
                }
                longestSubstring.pop();
            }
            
            longestSubstring.push(letter);
            seen.insert(letter);
            longestLength = max(longestLength, (int)longestSubstring.size());
        }
        
        return longestLength;
    }
};