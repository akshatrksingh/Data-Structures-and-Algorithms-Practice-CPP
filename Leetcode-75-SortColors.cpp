/*
class Solution 
{
    public:
        void sortColors(vector<int> &nums) 
        {
            int c0 = 0, c1 = 0, c2 = 0;
            for(int i: nums)
            {
                if(i == 0)
                    c0++;
                else if(i == 1)
                    c1++;
                else
                    c2++;
            }
            for(int &i: nums)
            {
                if(c0-- > 0)
                    i = 0;
                else if(c1-- > 0)
                    i = 1;
                else
                    i = 2;
            }
        }
};
*/
class Solution 
{
    public:
        void sortColors(vector<int> &nums) 
        {
            int j = 0, k = nums.size() - 1;
            for (int i = 0; i <= k; i++)
            {
                if (nums[i] == 0 && i != j)
                    swap(nums[i--], nums[j++]);
                else if (nums[i] == 2 && i != k)
                    swap(nums[i--], nums[k--]);
            }
        }
};
