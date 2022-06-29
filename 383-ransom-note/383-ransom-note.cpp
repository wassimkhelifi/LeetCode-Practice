class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> magazineOccurrences;
        for (auto& letter : magazine) {
            magazineOccurrences[letter]++;
        }
        
        for (auto& letter : ransomNote) {
            if (!magazineOccurrences.count(letter)) return false;
            else {
                magazineOccurrences[letter]--;
                if (magazineOccurrences[letter] < 0) return false;
            }
        }
        
        return true;
    }
};