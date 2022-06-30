class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        int size = heights.size();
        stack<pair<int, int>> indexHeights;
        for (int i = 0; i < size; i++) {
            int currentHeight = heights[i];
            int startingIndex = i;
            while (!indexHeights.empty() && indexHeights.top().second > currentHeight) {
                int index = indexHeights.top().first;
                int height = indexHeights.top().second;
                indexHeights.pop();
                maxArea = max(maxArea, height * (i - index));
                startingIndex = index;
            }
            
            indexHeights.push(make_pair(startingIndex, currentHeight));
        }
        
        while (!indexHeights.empty()) {
            int index = indexHeights.top().first;
            int height = indexHeights.top().second;
            indexHeights.pop();
            maxArea = max(maxArea, height * (size - index));
        }
        
        return maxArea;
    }
};