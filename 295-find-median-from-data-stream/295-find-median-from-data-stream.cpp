class MedianFinder {
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        smallHeap.push(num);
        if (!smallHeap.empty() && !largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else if (largeHeap.size() > smallHeap.size()) {
            return largeHeap.top();
        } else {
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */