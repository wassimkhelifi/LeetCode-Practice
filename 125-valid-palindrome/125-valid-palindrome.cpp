class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 1) return true;
        
        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i])) {
                s.erase(s.begin() + i);
                i--;
            } else s[i] = tolower(s[i]);
        }
        
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};