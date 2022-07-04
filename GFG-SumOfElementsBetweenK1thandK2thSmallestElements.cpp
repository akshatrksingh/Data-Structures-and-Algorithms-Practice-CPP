class Solution
{
    public:
    long long kthSmallest(long long arr[], long long n, long long k) 
    {
        priority_queue<long long> maxHeap;
        for(int i = 0; i < n; i++)       //n elements => TC: O(n)
        {
            maxHeap.push(arr[i]);         //push in max heap of k elements => TC: O(log k)
            if(maxHeap.size() > k)
                maxHeap.pop();            //pop from max heap of k elements => TC: O(log k)
        }                                 // Overall TC: O(n log k)
        return maxHeap.top();
    }
    long long sumBetweenTwoKth (long long arr[], long long n, long long k1, long long k2)
    {
        long long sum = 0;
        long long first = kthSmallest(arr, n, k1);
        long long second = kthSmallest(arr, n, k2);
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > first && arr[i] < second)
            {
                sum += arr[i];
            }
        }
        return sum;
    }
};
