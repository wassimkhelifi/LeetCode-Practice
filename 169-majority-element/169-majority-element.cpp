class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> occurrences;
        for (auto& num : nums) {
            occurrences[num]++;
        }
        
        int element;
        for (auto& entry : occurrences) {
            if (entry.second > nums.size() / 2) {
                element = entry.first;
            }
        }
        
        return element;
    }
};