class Solution {
public:
    int search(vector<int>& nums, int target) {
        return modifiedBinarySearch(nums, 0, nums.size() - 1, target);
    }
    
    int modifiedBinarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        
        int middle = (low + high) / 2;
        if (nums[middle] == target) return middle;
        
        if (nums[low] <= nums[middle]) {
            if (nums[low] <= target && target < nums[middle]) {
                return modifiedBinarySearch(nums, low, middle - 1, target);
            } else {
                return modifiedBinarySearch(nums, middle + 1, high, target);
            }
        } else {
            if (nums[middle] <= target && target <= nums[high]) {
                return modifiedBinarySearch(nums, middle + 1, high, target);
            } else {
                return modifiedBinarySearch(nums, low, middle - 1, target);
            }
        }
    }
};