class MedianFinder {
    // Max heap: stores the smaller half of the numbers.
    priority_queue<int> lower;

    // Min heap: stores the larger half of the numbers.
    priority_queue<int, vector<int>, greater<int>> upper;

public:
    MedianFinder() {}

    void addNum(int num) {
        // Insert the number into the appropriate half.
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        // Keep lower the same size as upper, or one larger.
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        // Even count: average the two middle numbers.
        if (lower.size() == upper.size())
            return ((double)lower.top() + upper.top()) / 2.0;

        // Odd count: lower contains the middle number.
        return lower.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */