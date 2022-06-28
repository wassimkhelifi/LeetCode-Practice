class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) return -1;
        
        int middle = (low + high) / 2;
        if (nums[middle] == target) return middle;
        if (target < nums[middle]) {
            return binarySearch(nums, low, middle - 1, target);
        } else {
            return binarySearch(nums, middle + 1, high, target);
        }
    }
};