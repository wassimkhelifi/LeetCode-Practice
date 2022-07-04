class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tmap;
        for (auto& character : t) {
            tmap[character]++;
        }
        
        map<char, int> smap;
        pair<int, int> minWindowIndices = {-1, -1};
        int minWindowLength = INT_MAX;
        int requiredLetters = tmap.size();
        int validLetters = 0;
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            smap[s[right]]++;
            if (smap[s[right]] == tmap[s[right]]) {
                validLetters++;
            }
            while (validLetters == requiredLetters) {
                if (right - left + 1 < minWindowLength) {
                    minWindowLength = right - left + 1;
                    minWindowIndices = {left, right};
                }
                smap[s[left]]--;
                if (smap[s[left]] < tmap[s[left]]) {
                    validLetters--;
                }
                left++;
            }
        }
        
        if (minWindowLength == INT_MAX) {
            return "";
        } else {
            return s.substr(minWindowIndices.first, minWindowLength);
        }
    }
};