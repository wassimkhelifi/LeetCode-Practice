class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> smap;
        map<char, int> pmap;
        for (int i = 0; i < p.size(); i++) {
            pmap[p[i]]++;
            smap[s[i]]++;
        }
        
        vector<int> anagramIndices;
        if (smap == pmap) {
            anagramIndices.push_back(0);
        }
        
        int left = 0;
        for (int right = p.size(); right < s.size(); right++) {
            smap[s[left]]--;
            if (!smap[s[left]]) {
                smap.erase(s[left]);
            }
            left++;
            smap[s[right]]++;
            if (smap == pmap) {
                anagramIndices.push_back(left);
            }
        }
        
        return anagramIndices;
    }
};