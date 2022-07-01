class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complementToIndex;
        for (int i = 0; i < nums.size(); i++) {
            complementToIndex[target - nums[i]] = i;
        }
        
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (complementToIndex.count(nums[i]) && i != complementToIndex[nums[i]]) {
                indices = {i, complementToIndex[nums[i]]};
                break;
            }
        }
        
        return indices;
    }
};