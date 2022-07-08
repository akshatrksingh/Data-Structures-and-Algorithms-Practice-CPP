class Solution 
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) 
        {
            int n = nums.size();
            vector<vector<int>> ans;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < n; i++)
            {
                if(i > 0  && nums[i] == nums[i-1])
                    continue;       
                long long temp_target1 = target-nums[i];
                for(int j = i+1;j < n; j++)
                {
                    if(j > i+1 && nums[j] == nums[j-1])
                        continue;    
                    long long temp_target2 = temp_target1-nums[j];
                    int left = j+1, right = n-1;
                    while(left < right)
                    {
                        if(nums[left] + nums[right] == temp_target2)
                        {
                            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                            while(left < right && nums[right] == nums[right-1]) 
                                right--;
                            while(left < right && nums[left] == nums[left+1]) 
                                left++;
                            left++;
                            right--;
                        }
                        else if(nums[left] + nums[right] < temp_target2)
                        {
                            left++;
                        }
                        else 
                        {
                            right--;
                        }
                    }
                }
            }
            return ans;
        }
};
