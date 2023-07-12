// Comparator in pq is reverse of that of sort and other operations

class Comparator 
{
    public:
      bool operator() (const pair<int, int> &a, const pair<int, int> &b) 
      {
        if (a.first == b.first) 
            return a.second < b.second;   // desc
        else
            return a.first > b.first;     // asc
      }
};
class Solution 
{
    public:
        vector<int> frequencySort(vector<int>& nums) 
        {
            unordered_map<int, int> freq;
            for(int num: nums)
            {cus
                freq[num]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap;
            for(auto it = freq.begin(); it != freq.end(); it++)
            {
                minHeap.push(make_pair(it->second, it->first));
            }
            
            vector<int> ans;
            while(!minHeap.empty())
            {
                int freq = minHeap.top().first;
                int num = minHeap.top().second;
                for(int i = 0; i < freq; i++)
                    ans.push_back(num);
                minHeap.pop();
            }
            return ans;
        }
};
/*
// pq

#include <iostream>
#include <vector>
#include <queue>

class ComparePairs 
{
    public:
        bool operator()(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) 
        {
            if (pair1.first == pair2.first)
                return pair1.second < pair2.second; // Sort in descending order of the second element if the first elements are equal
            else
                return pair1.first > pair2.first;   // Sort in ascending order of the first element
        }
};

int main() 
{
    std::vector<std::pair<int, int>> pairs = {{2, 3}, {3, 3}, {3, 4}, {3, 5}, {4, 5}};

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ComparePairs> pq;

    // Insert elements from the vector into the priority queue
    for (const auto& pair : pairs) 
    {
        pq.push(pair);
    }

    // Print the sorted pairs by popping elements from the priority queue
    while (!pq.empty()) 
    {
        std::pair<int, int> pair = pq.top();
        pq.pop();
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    return 0;
} 

// sort

#include <iostream>
#include <vector>
#include <algorithm>

class ComparePairs 
{
    public:
        bool operator()(const std::pair<int, int>& pair1, const std::pair<int, int>& pair2) {
            if (pair1.first == pair2.first)
                return pair1.second > pair2.second; // Sort in descending order of the second element if the first elements are equal
            else
                return pair1.first < pair2.first;   // Sort in ascending order of the first element
        }
};

int main() 
{
    std::vector<std::pair<int, int>> pairs = {{2, 3}, {3, 3}, {3, 4}, {3, 5}, {4, 5}};

    std::sort(pairs.begin(), pairs.end(), ComparePairs());

    // Print the sorted pairs
    for (const auto& pair : pairs) 
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}


*/
