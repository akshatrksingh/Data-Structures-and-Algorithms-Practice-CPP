class Solution 
{
    public:
        void rotate(vector<int>& nums, int k) 
        {
            int n = nums.size();
            vector<int> v(n);
            for(int i = 0; i < n; i++)
            {
                v[i] = nums[(i-k%n+n)%n];
            }
            nums = v;
        }
};
