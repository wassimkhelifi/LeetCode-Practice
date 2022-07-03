class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums.front();
        int maxSum = nums.front();
        nums.erase(nums.begin());
        for (auto& number : nums) {
            currentSum = max(currentSum + number, number);
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};