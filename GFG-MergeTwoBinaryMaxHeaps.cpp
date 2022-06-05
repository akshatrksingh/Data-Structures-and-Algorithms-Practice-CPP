class Solution
{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        for(auto i: a)
        {
            b.push_back(i);
        }
        make_heap(b.begin(), b.end());
        return b;
    }
};
