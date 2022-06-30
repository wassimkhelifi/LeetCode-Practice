class Solution {
public:
    bool isValid(string s) {
        if (s.front() == ')' || s.front() == '}' || s.front() == ']') return false;
        
        stack<char> mystack;
        for (auto& bracket : s) {
            if (bracket == ')' || bracket == '}' || bracket == ']') {
                if (mystack.empty()) return false;
                char topBracket = mystack.top();
                mystack.pop();
                if ((topBracket == '(' && bracket != ')') || (topBracket == '{' && bracket != '}') || (topBracket == '[' && bracket != ']')) {
                    return false;
                }
            } else {
                mystack.push(bracket);
            }
        }
        
        return mystack.empty();
    }
};