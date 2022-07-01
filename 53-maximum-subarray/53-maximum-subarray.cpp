class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums.front();
        int maxSum = nums.front();
        nums.erase(nums.begin());
        for (auto& num : nums) {
            currentSum = max(currentSum + num, num);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};