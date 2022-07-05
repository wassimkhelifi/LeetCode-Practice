class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombinations;
        vector<int> currentCombination;
        obtainCombinations(candidates, 0, target, currentCombination, allCombinations);
        return allCombinations;
    }
    
    void obtainCombinations(vector<int>& candidates, int index, int target, vector<int>& currentCombination, vector<vector<int>>& allCombinations) {
        if (target == 0) {
            allCombinations.push_back(currentCombination);
            return;
        }
        if (target < 0 or index >= candidates.size()) {
            return;
        }
        
        obtainCombinations(candidates, index + 1, target, currentCombination, allCombinations);
        currentCombination.push_back(candidates[index]);
        obtainCombinations(candidates, index, target - candidates[index], currentCombination, allCombinations);
        currentCombination.pop_back();
    }
};