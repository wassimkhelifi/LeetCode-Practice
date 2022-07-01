class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int middle = 0;
        int right = nums.size() - 1;
        
        while (middle <= right) {
            if (nums[middle] == 0) {
                swap(nums[left++], nums[middle++]);
            } else if (nums[middle] == 1) {
                middle++;
            } else {
                swap(nums[middle], nums[right--]);
            }
        }
    }
};