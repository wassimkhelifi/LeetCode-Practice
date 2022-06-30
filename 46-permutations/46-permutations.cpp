class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        obtainPermutations(nums, 0, nums.size() - 1, allPermutations);
        return allPermutations;
    }
    
    void obtainPermutations(vector<int>& currentPermutation, int left, int right, vector<vector<int>>& allPermutations) {
        if (left == right) {
            allPermutations.push_back(currentPermutation);
            return;
        }
        
        for (int i = left; i <= right; i++) {
            swap(currentPermutation[i], currentPermutation[left]);
            obtainPermutations(currentPermutation, left + 1, right, allPermutations);
            swap(currentPermutation[i], currentPermutation[left]);
        }
    }
};