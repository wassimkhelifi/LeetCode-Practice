class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombinations;
        vector<int> currentCombination;
        obtainCombinations(candidates, currentCombination, 0, target, allCombinations);
        return allCombinations;
    }
    
    void obtainCombinations(vector<int>& candidates, vector<int>& currentCombination, int index, int target, vector<vector<int>>& combinations) {
        if (target == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        if (index >= candidates.size() || target < 0) {
            return;
        }
        
        obtainCombinations(candidates, currentCombination, index + 1, target, combinations);
        
        currentCombination.push_back(candidates[index]);
        obtainCombinations(candidates, currentCombination, index, target - candidates[index], combinations);
        currentCombination.pop_back();
    }
};