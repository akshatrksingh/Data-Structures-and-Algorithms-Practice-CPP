class Solution 
{
    public:
        int removeDuplicates(vector<int>& nums) 
        {
            int p1 = 0, p2 = 1, n = nums.size(), k = 1;
            for(int p2 = 1; p2 < n; p2++)
            {
                if(nums[p1] != nums[p2])
                {
                    k++;
                    nums[++p1] = nums[p2];
                }
            }
            return k;
        }
};
