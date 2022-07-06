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
    
    /**
    digits size = d
    required size = r
    
    */
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<vector<string>> required;
        for (auto& digit : digits) { // O(d)
            required.push_back(digitToLetters[digit]);
        }
        
        vector<string> combinations = {required.front()};
        required.erase(required.begin());
        for (auto& requiredLetters : required) {
            combinations = combine(combinations, requiredLetters);
        }
        
        return combinations;
    }
    
    vector<string> combine(vector<string>& combinations, vector<string>& required) {
        vector<string> newCombinations;
        for (auto& combination : combinations) {
            for (auto& letter : required) {
                newCombinations.push_back(combination + letter);
            }
        }
        
        return newCombinations;
    }
};