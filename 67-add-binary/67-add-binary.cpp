class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty()) return "";
        if (!a.empty() && b.empty()) return a;
        if (a.empty() && !b.empty()) return b;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string result = "";
        int index = 0;
        bool carryOver = false;
        while (index < a.size() && index < b.size()) {
            if (a[index] == '0' && b[index] == '0') {
                if (carryOver) result += '1';
                else result += '0';
                carryOver = false;
            } else if (a[index] == '1' && b[index] == '1') {
                if (carryOver) result += '1';
                else result += '0';
                carryOver = true;
            } else {
                if (carryOver) {
                    result += '0';
                    carryOver = true;
                } else {
                    result += '1';
                    carryOver = false;
                }
            }
            index++;
        }
        
        while (index < a.size()) {
            if (carryOver) {
                if (a[index] == '1') {
                    result += '0';
                    carryOver = true;
                } else {
                    result += '1';
                    carryOver = false;
                }
            } else {
                result += a[index];
            }
            index++;
        }
        
        while (index < b.size()) {
            if (carryOver) {
                if (b[index] == '1') {
                    result += '0';
                    carryOver = true;
                } else {
                    result += '1';
                    carryOver = false;
                }
            } else {
                result += b[index];
            }
            index++;
        }
        
        if (carryOver) result += '1';
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};