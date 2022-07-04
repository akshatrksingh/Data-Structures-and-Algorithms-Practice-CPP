class MedianFinder 
{
    public:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        double median = 0;
        void addNum(int curr) 
        {
            if(maxHeap.size() == minHeap.size())
            {
                if(curr < median)
                {
                    maxHeap.push(curr);
                    median = maxHeap.top();
                }
                else 
                {
                    minHeap.push(curr);
                    median = minHeap.top();
                }
            }
            else if(maxHeap.size() > minHeap.size())
            {
                if(curr < median)
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(curr);
                }
                else 
                {
                    minHeap.push(curr);
                }
                median = (double)(maxHeap.top() + minHeap.top())/2;
            }
            else if(maxHeap.size() < minHeap.size())
            {
                if(curr < median)
                {
                    maxHeap.push(curr);
                }
                else 
                {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(curr);
                }
                median = (double)(maxHeap.top() + minHeap.top())/2;
            }
        }

        double findMedian() 
        {
            return median;
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
