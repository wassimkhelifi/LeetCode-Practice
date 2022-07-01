class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> triples;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    vector<int> triple = {nums[i], nums[left], nums[right]};
                    triples.push_back(triple);
                    while (left < right && nums[left] == triple[1]) {
                        left++;
                    }
                    while (left < right && nums[right] == triple[2]) {
                        right--;
                    }
                }
            }
            
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return triples;
    }
};