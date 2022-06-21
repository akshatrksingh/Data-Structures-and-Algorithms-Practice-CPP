class Solution
{
  public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> v;
        list<int> l;
        int i = 0, j = 0;
        while(j < n)
        {
            while(l.size() > 0 && l.back() < arr[j])
            {
                l.pop_back();
            }
            l.push_back(arr[j]);
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                v.push_back(l.front());
                if(l.front() == arr[i])
                {
                    l.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
    }
};
