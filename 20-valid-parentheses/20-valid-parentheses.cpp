class Solution {
public:
    bool isValid(string s) {
        if (s.front() == ')' || s.front() == '}' || s.front() == ']') {
            return false;
        }
        
        stack<char> openBrackets;
        for (auto& bracket : s) {
            if (bracket == ')' || bracket == '}' || bracket == ']') {
                if (openBrackets.empty()) {
                    return false;
                }
                char openBracket = openBrackets.top(); openBrackets.pop();
                if ((openBracket == '(' && bracket != ')') || (openBracket == '{' && bracket != '}') || (openBracket == '[' && bracket != ']')) {
                    return false;
                }
            } else {
                openBrackets.push(bracket);
            }
        }
        
        return openBrackets.empty();
    }
};