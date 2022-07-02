class Solution {
public:
    map<char, vector<string>> digitToLetters = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}},
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<vector<string>> requiredLetters;
        for (auto& digit : digits) {
            requiredLetters.push_back(digitToLetters[digit]);
        }
        
        vector<string> combinations = requiredLetters.front();
        requiredLetters.erase(requiredLetters.begin());
        if (requiredLetters.empty()) return combinations;
        
        for (auto& required : requiredLetters) {
            combinations = combine(combinations, required);
        }
        
        return combinations;
    }
    
    vector<string> combine(vector<string>& combinations, vector<string>& requiredLetters) {
        vector<string> newCombinations;
        for (auto& combination : combinations) {
            for (auto& required : requiredLetters) {
                newCombinations.push_back(combination + required);
            }
        }
        
        return newCombinations;
    }
};