class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<vector<int>, double> pointToDistance;
        for (auto& point : points) {
            pointToDistance.insert(make_pair(point, distance(point)));
        }
        
        multimap<double, vector<int>> distanceToPoint;
        for (auto& entry : pointToDistance) {
            distanceToPoint.insert(make_pair(entry.second, entry.first));
        }
        
        vector<vector<int>> kClosestPoints;
        auto point = distanceToPoint.begin();
        while (k != 0) {
            kClosestPoints.push_back(point -> second);
            point++;
            k--;
        }
        
        return kClosestPoints;
    }
    
    double distance(vector<int>& point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
};