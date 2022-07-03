class Solution 
{
    public:
        int findKthLargest(vector<int>& nums, int k) 
        {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int i = 0; i < nums.size(); i++)        //n elements => TC: O(n)
            {
                minHeap.push(nums[i]);                   //push in max heap of k elements => TC: O(log k)
                if(minHeap.size() > k)
                    minHeap.pop();                      //pop from max heap of k elements => TC: O(log k)
            }                                           // Overall TC: O(n log k)
            return minHeap.top();
        }
};
