class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int>& currentInterval = intervals[i];
            if (newInterval.back() < currentInterval.front()) {
                mergedIntervals.push_back(newInterval);
                mergedIntervals.insert(mergedIntervals.end(), intervals.begin() + i, intervals.end());
                return mergedIntervals;
            } else if (newInterval.front() > currentInterval.back()) {
                mergedIntervals.push_back(currentInterval);
            } else {
                newInterval = {{min(newInterval.front(), currentInterval.front()), max(newInterval.back(), currentInterval.back())}};
            }
        }
        
        mergedIntervals.push_back(newInterval);
        
        return mergedIntervals;
    }
};