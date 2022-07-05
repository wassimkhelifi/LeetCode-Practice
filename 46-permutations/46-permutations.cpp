class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        obtainPermutations(nums, 0, nums.size() - 1, allPermutations);
        return allPermutations;
    }
    
    void obtainPermutations(vector<int>& nums, int left, int right, vector<vector<int>>& allPermutations) {
        if (left == right) {
            allPermutations.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++) {
            swap(nums[i], nums[left]);
            obtainPermutations(nums, left + 1, right, allPermutations);
            swap(nums[i], nums[left]);
        }
    }
};