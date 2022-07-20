/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution 
{
    public:
        int binarySearchAscending(MountainArray &nums, int lb, int ub, int target) 
        {
            int mid, m;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                m = nums.get(mid);
                if(m == target)
                {
                    return mid;
                }
                else if(m < target)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            return -1;
        }
        int binarySearchDescending(MountainArray &nums, int lb, int ub, int target) 
            {
                int mid, m;
                while(lb <= ub)
                {
                    mid = lb + (ub-lb)/2;
                    m = nums.get(mid);
                    if(m == target)
                    {
                        return mid;
                    }
                    else if(m < target)
                    {
                        ub = mid-1;
                    }
                    else
                    {
                        lb = mid+1;
                    }
                }
                return -1;
            }
        int peakIndexInMountainArray(MountainArray &nums)
        {
            int n = nums.length();
            int lb = 1 , mid, m, ub = n-2;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                m = nums.get(mid);
                if(nums.get(mid-1) < m && m > nums.get(mid+1))
                {
                    return mid;
                }
                else if(nums.get(mid-1) < m)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }            
            return -1;
        }
        int findInMountainArray(int target, MountainArray &nums) 
        {
            int p = peakIndexInMountainArray(nums);
            int a = binarySearchAscending(nums, 0, p, target);
            int b = binarySearchDescending(nums, p+1, nums.length()-1, target);
            if(a == -1 && b == -1)
                return -1;
            else if(a == -1)
                return b;
            else
                return a;
        }
    };
