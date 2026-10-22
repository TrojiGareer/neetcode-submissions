#include <queue>

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == 0 || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else minHeap.push(num);
        if (maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if ((maxHeap.size() + minHeap.size()) % 2 == 1) return maxHeap.top();
        else return (maxHeap.top() + minHeap.top()) / 2.0f;
    }
};
