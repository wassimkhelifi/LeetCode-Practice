class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> tmap;
        for (auto& letter : t) tmap[letter]++;
        
        map<char, int> smap;
        pair<int, int> substringIndices = {-1, -1};
        int substringLength = INT_MAX;
        int requiredLettersCount = tmap.size();
        int validLettersCount = 0;
        
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            smap[s[right]]++;
            if (smap[s[right]] == tmap[s[right]]) validLettersCount++;
            while (validLettersCount == requiredLettersCount) {
                if (right - left + 1 < substringLength) {
                    substringLength = right - left + 1;
                    substringIndices = {left, right};
                }
                smap[s[left]]--;
                if (tmap[s[left]] > smap[s[left]]) validLettersCount--;
                left++;
            }
        }
        
        if (substringLength == INT_MAX) return "";
        else return s.substr(substringIndices.first, substringLength);
    }
};