class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        
        vector<int> maxLeft(size);
        maxLeft[0] = height.front();
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        
        vector<int> maxRight(size);
        maxRight[height.size() - 1] = height.back();
        for (int i = height.size() - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        
        int totalTrapped = 0;
        for (int i = 0; i < height.size(); i++) {
            totalTrapped += min(maxLeft[i], maxRight[i]) - height[i];
        }
        
        return totalTrapped;
    }
};