class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> mergedIntervals = {intervals.front()};
        intervals.erase(intervals.begin());
        
        int index = 0;
        for (auto& interval : intervals) {
            vector<int>& mergedInterval = mergedIntervals[index];
            if (interval.front() <= mergedInterval.back() && interval.back() >= mergedInterval.back()) {
                mergedInterval = {mergedInterval.front(), interval.back()};
            } else if (interval.front() >= mergedInterval.back() && interval.back() >= mergedInterval.back()) {
                mergedIntervals.push_back(interval);
                index++;
            }
        }
        
        return mergedIntervals;
    }
};