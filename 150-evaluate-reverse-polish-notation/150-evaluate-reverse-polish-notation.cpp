class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (auto& token : tokens) {
            if (token.size() == 1 && !isdigit(token.front())) {
                int numberTwo = numbers.top(); numbers.pop();
                int numberOne = numbers.top(); numbers.pop();
                numbers.push(calculate(numberOne, numberTwo, token));
            } else {
                numbers.push(stoi(token));
            }
        }
        
        return numbers.top();
    }
    
    int calculate(int numberOne, int numberTwo, string operand) {
        if (operand == "+") {
            return numberOne + numberTwo;
        } else if (operand == "-") {
            return numberOne - numberTwo;
        } else if (operand == "*") {
            return numberOne * numberTwo;
        } else {
            return numberOne / numberTwo;
        }
    }
};