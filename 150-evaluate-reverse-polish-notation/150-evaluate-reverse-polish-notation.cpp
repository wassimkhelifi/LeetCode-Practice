class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (auto& token : tokens) {
            if (token.size() == 1 && !isdigit(token.front())) {
                int secondNumber = numbers.top(); numbers.pop();
                int firstNumber = numbers.top(); numbers.pop();
                numbers.push(calculate(firstNumber, secondNumber, token));
            } else {
                numbers.push(stoi(token));
            }
        }
        
        return numbers.top();
    }
    
    int calculate(int firstNumber, int secondNumber, string operand) {
        if (operand == "+") return firstNumber + secondNumber;
        else if (operand == "-") return firstNumber - secondNumber;
        else if (operand == "*") return firstNumber * secondNumber;
        else return firstNumber / secondNumber;
    }
};