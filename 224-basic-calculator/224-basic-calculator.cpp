class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int currentNumber = 0;
        int result = 0;
        stack<int> partialResults;
        for (auto& character : s) {
            if (isdigit(character)) {
                currentNumber = currentNumber * 10 + (character - '0');
            } else if (character == '+' || character == '-') {
                result += (currentNumber * sign);
                if (character == '-') {
                    sign = -1;
                } else {
                    sign = 1;
                }
                currentNumber = 0;
            } else if (character == '(') {
                partialResults.push(result);
                partialResults.push(sign);
                result = 0;
                sign = 1;
                currentNumber = 0;
            } else if (character == ')') {
                result += (currentNumber * sign);
                result *= partialResults.top(); partialResults.pop();
                result += partialResults.top(); partialResults.pop();
                currentNumber = 0;
                sign = 1;
            }
        }
        
        return result + (currentNumber * sign);
    }
};