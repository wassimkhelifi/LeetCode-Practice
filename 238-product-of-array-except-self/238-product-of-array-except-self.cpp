class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left = {1};
        for (int i = 1; i < nums.size(); i++) {
            left.push_back(left[i - 1] * nums[i - 1]);
        }
        
        vector<int> right = {1};
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            right.push_back(right[i - 1] * nums[i - 1]);
        }
        reverse(right.begin(), right.end());
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(left[i] * right[i]);
        }
        
        return result;
    }
};

/**
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left = {1};
        for (int i = 1; i < nums.size(); i++) {
            left.push_back(left[i - 1] * nums[i - 1]);
        }
        
        vector<int> right = {1};
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            right.push_back(right[i - 1] * nums[i - 1]);
        }
        reverse(right.begin(), right.end());
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(left[i] * right[i]);
        }
        
        return result;
    }
};
*/