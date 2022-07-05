class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int size = heights.size();
        stack<pair<int, int>> startingIndexHeights;
        for (int i = 0; i < size; i++) {
            int currentHeight = heights[i];
            int startingIndex = i;
            while (!startingIndexHeights.empty() && startingIndexHeights.top().second > currentHeight) {
                int index = startingIndexHeights.top().first;
                int height = startingIndexHeights.top().second;
                startingIndexHeights.pop();
                maxArea = max(maxArea, height * (i - index));
                startingIndex = index;
            }
            startingIndexHeights.push(make_pair(startingIndex, currentHeight));
        }
        
        while (!startingIndexHeights.empty()) {
            int index = startingIndexHeights.top().first;
            int height = startingIndexHeights.top().second;
            startingIndexHeights.pop();
            maxArea = max(maxArea, height * (size - index));
        }
        
        return maxArea;
    }
};