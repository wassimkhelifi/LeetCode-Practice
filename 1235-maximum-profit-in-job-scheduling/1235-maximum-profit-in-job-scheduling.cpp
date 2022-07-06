class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        map<int, int> endTimeToProfit;
        endTimeToProfit[0] = 0;
        for (auto& job : jobs) {
            int possibleProfit = prev(endTimeToProfit.upper_bound(job[1])) -> second + job[2];
            if (possibleProfit > endTimeToProfit.rbegin() -> second) {
                endTimeToProfit[job[0]] = possibleProfit;
            }
        }
        
        return endTimeToProfit.rbegin() -> second;
    }
};