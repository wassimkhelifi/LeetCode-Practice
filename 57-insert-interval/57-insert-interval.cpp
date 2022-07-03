class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals = {intervals.front()};
        intervals.erase(intervals.begin());
        
        int index = 0;
        for (auto& interval : intervals) {
            vector<int>& topInterval = mergedIntervals[index]; 
            if (interval.front() <= topInterval.back() && interval.back() >= topInterval.back()) {
                topInterval = {topInterval.front(), interval.back()};
            } else if (interval.front() >= topInterval.back() && interval.back() >= topInterval.back()) {
                mergedIntervals.push_back(interval);
                index++;
            }
        }
        
        return mergedIntervals;
    }
};