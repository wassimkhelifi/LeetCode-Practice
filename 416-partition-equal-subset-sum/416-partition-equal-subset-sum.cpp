class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) sum += num;
        if (sum % 2) return false;
        
        map<pair<int, int>, bool> indexTargetPairs;
        
        return obtainPartitions(nums, 0, sum / 2, indexTargetPairs);
    }
    
    bool obtainPartitions(vector<int>& nums, int index, int target, map<pair<int, int>, bool>& indexTargetPairs) {
        if (target == 0) return true;
        if (target < 0 || index >= nums.size()) return false;
        
        pair<int, int> currentIndexTarget = make_pair(index, target);
        if (indexTargetPairs.count(currentIndexTarget)) return indexTargetPairs[currentIndexTarget];
        
        return indexTargetPairs[currentIndexTarget] =
            obtainPartitions(nums, index + 1, target - nums[index], indexTargetPairs) ||
            obtainPartitions(nums, index + 1, target, indexTargetPairs);
    }
};