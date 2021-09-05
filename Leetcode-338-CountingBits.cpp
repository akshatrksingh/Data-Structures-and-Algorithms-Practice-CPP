class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> arr;
        arr.push_back(0);
        if(n == 0)
        {
            return arr;
        }
        arr.push_back(1);
        for(int i = 2; i <= n; i++)
        {
            arr.push_back(arr[i/2] + i%2);
        }
        return arr;
    }
};
