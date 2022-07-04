class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        
        int index = 0;
        while (index < s.size() && isspace(s[index])) {
            index++;
        }
        
        bool isPositive = true;
        if (index < s.size() && (s[index] == '+' || s[index] == '-')) {
            if (s[index] == '-') {
                isPositive = false;
            }
            index++;
        }
        
        int integer = 0;
        while (index < s.size() && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (integer > INT_MAX / 10 || (integer == INT_MAX / 10 && digit > INT_MAX % 10)) {
                if (isPositive) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            integer = integer * 10 + digit;
            index++;
        }
        
        if (isPositive) {
            return integer;
        } else {
            return -integer;
        }
    }
};