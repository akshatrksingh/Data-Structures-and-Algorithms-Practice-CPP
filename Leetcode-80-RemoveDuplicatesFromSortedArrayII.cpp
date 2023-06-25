class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int n = nums.size();
            if(n <= 2)
                return n;
            int p1 = 1, p2 = 2;
            for(int p2 = 2; p2 < n; p2++)
            {
                if(nums[p1-1] != nums[p2])
                {
                    nums[++p1] = nums[p2];
                }
            }
            return p1+1;
        }
};
