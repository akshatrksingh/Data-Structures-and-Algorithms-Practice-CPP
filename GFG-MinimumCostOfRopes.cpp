class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) 
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long cost = 0, first, second;
        for(int i = 0; i < n; i++)
        {
            minHeap.push(arr[i]);
        }
        while(minHeap.size() >= 2)
        {
            first = minHeap.top();
            minHeap.pop();
            second = minHeap.top();
            minHeap.pop();
            cost += first + second;
            minHeap.push(first+second);
        }
        return cost;
    }
};
