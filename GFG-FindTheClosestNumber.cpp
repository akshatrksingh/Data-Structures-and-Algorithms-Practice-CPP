class Solution
{
    public:
    int findClosest(int nums[], int n, int target) 
    { 
            int lb = 0 , mid, ub = n-1;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == target)
                {
                    return nums[mid];
                }
                else if(nums[mid] < target)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            if(lb > n-1)
                return nums[ub];
            else if(ub < 0)
                return nums[lb];
            return (abs(nums[ub]-target) < abs(nums[lb]-target)) ? nums[ub]: nums[lb] ;
    } 
};
