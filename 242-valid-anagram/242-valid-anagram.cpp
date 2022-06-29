class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> sOccurrences;
        for (auto& letter : s) {
            sOccurrences[letter]++;
        }
        
        map<char, int> tOccurrences;
        for (auto& letter : t) {
            tOccurrences[letter]++;
        }
        
        return sOccurrences == tOccurrences;
    }
};