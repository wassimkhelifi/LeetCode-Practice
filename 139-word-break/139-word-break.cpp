class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        vector<bool> memo(s.size(), false);
        memo[0] = true;
        
        for (int right = 1; right <= s.size(); right++) {
            for (int left = right - 1; left >= 0; left--) {
                if (memo[left]) {
                    string substring = s.substr(left, right - left);
                    if (wordSet.count(substring)) {
                        memo[right] = true;
                        break;
                    }
                }
            }
        }
        
        return memo[s.size()];
    }
};