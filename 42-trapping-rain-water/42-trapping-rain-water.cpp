class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        
        vector<int> maxLeft(size, -1);
        maxLeft[0] = height.front();
        for (int i = 1; i < height.size(); i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        
        vector<int> maxRight(size, -1);
        maxRight[size - 1] = height.back();
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        
        int totalTrapped = 0;
        for (int i = 0; i < size; i++) {
            totalTrapped += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return totalTrapped;
    }
};