class Solution
{
    public:
        vector <int> nearlySorted(int arr[], int n, int k)
        {
            vector<int> ans;
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int i = 0; i < n; i++)
            {
                minHeap.push(arr[i]);
                if(minHeap.size() > k)
                {
                    ans.push_back(minHeap.top());
                    minHeap.pop();
                }
            }
            while(!minHeap.empty())
            {
                ans.push_back(minHeap.top());
                minHeap.pop();
            }
            return ans;
        }
};
