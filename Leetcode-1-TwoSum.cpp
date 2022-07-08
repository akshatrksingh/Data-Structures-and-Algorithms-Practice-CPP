class Solution 
{
    public:
        vector<int> twoSum(vector<int> &nums, int target) 
        {
            int n = nums.size();
            vector<int> copy, ans;
            copy = nums;
            sort(copy.begin(), copy.end());
            int left = 0, right = n-1;
            while(left < right)
            {
                if(copy[left] + copy[right] == target)
                break;
                else if(copy[left] + copy[right] > target)
                right--;
                else
                left++;
            }
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == copy[left])
                    ans.push_back(i);
                else if(nums[i] == copy[right])
                    ans.push_back(i);
            }
            return ans;
        }
};
