class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) return false;
        
        unordered_set<int> visited;
        for (auto& num : nums) {
            if (visited.count(num)) return true;
            visited.insert(num);
        }
        
        return false;
    }
};