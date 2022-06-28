// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return modifiedBinarySearch(0, n - 1);
    }
    
    int modifiedBinarySearch(int low, int high) {
        int middle = low + (high - low) / 2;
        if (isBadVersion(middle)) {
            if (!isBadVersion(middle - 1)) return middle;
            else {
                return modifiedBinarySearch(low, middle - 1);
            }
        } else {
            return modifiedBinarySearch(middle + 1, high);
        }
    }
};