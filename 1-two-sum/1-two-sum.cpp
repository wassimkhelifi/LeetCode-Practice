class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> complementToIndex;
        for (int i = 0; i < nums.size(); i++) {
            complementToIndex[target - nums[i]] = i;
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (complementToIndex.count(nums[i])) {
                int index = complementToIndex[nums[i]];
                if (index != i) {
                    result = {i, index};
                    break;
                }
            }
        }
        
        return result;
    }
};