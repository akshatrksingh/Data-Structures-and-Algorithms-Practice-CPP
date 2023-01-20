class Solution 
{
    public:
        int jump(vector<int>& nums) 
        {
            int n = nums.size(), reach = 0, numOfJumps = 0, currentIntervalEnd = 0, i;
            for(i = 0; i < n-1 && i <= reach; i++) 
            {
                reach = max(reach, nums[i]+i);
                if(i == currentIntervalEnd) 
                {                                                 
                    numOfJumps++;                                 
                    currentIntervalEnd = reach;   
                }                                            
            }                                                
            return numOfJumps;                               
    }
};
