class Solution 
{
    public:
        int maxProduct(vector<int>& v) 
        {
            make_heap(v.begin(), v.end());
            int m = v.front()-1;
            pop_heap(v.begin(), v.end()); //moves the largest to the end
            v.pop_back();
            make_heap(v.begin(), v.end());
            return m*(v.front()-1);
        }
};
