/*

// TLE

#define PII pair<int, int>

class Comparator
{
    public:
        bool operator()(const PII &a, const PII &b)
        {
            return (a.first+a.second) > (b.first+b.second);    // asc
        }
};

class Solution 
{
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
        {
            priority_queue<PII, vector<PII>, Comparator> minHeap;
            vector<vector<int>> v;
            for(int i = 0; i < nums1.size() && i < k; i++)
            {
                for(int j = 0; j < nums2.size() && j < k; j++)
                {
                    minHeap.push({nums1[i], nums2[j]});
                }
            }
            
            while(minHeap.size() && k--)
            {
                v.push_back({minHeap.top().first, minHeap.top().second});
                minHeap.pop();
            }
            return v;
        }
};

*/

#define PII pair<int, int>

class Comparator
{
    public:
        bool operator()(const PII &a, const PII &b)
        {
            return (a.first+a.second) < (b.first+b.second);    // desc
        }
};

class Solution 
{
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
        {
            priority_queue<PII, vector<PII>, Comparator> maxHeap;
            vector<vector<int>> v;
            for(int i = 0; i < nums1.size() && i < k; i++)
            {
                for(int j = 0; j < nums2.size() && j < k; j++)
                {
                    if(maxHeap.size() < k)   
                    {
                        maxHeap.push({nums1[i], nums2[j]});
                    }
                    else if(maxHeap.size() == k && (nums1[i] + nums2[j]) < maxHeap.top().first + maxHeap.top().second) 
                    {
                        maxHeap.pop();
                        maxHeap.push({nums1[i],nums2[j]});
                    }
                    else if(maxHeap.size() == k && (nums1[i] + nums2[j]) > maxHeap.top().first + maxHeap.top().second) 
                    {
                        break;
                    }
                }
            }
            while(maxHeap.size())
            {
                v.push_back({maxHeap.top().first, maxHeap.top().second});
                maxHeap.pop();
            }
            return v;
        }
};
