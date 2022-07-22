// https://leetcode.com/problems/divide-chocolate/
#include <bits/stdc++.h>
class Solution 
{
    public:
        bool isValid(vector<int> nums, int n, int m, int min_sum)
        {
            int piece = 0;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += nums[i];
                if(sum >= min_sum)   // maximize min_sum
                {
                    piece++;
                    sum = 0;
                }
            }
            if(piece < m)
                return false;
            return true;
        }
        int maximizeSweetness(vector<int> &sweetness, int k) 
        {
                int lb = 0;
                int ub = accumulate(sweetness.begin(), sweetness.end(), 0);
                int res = -1;
                while(lb <= ub)
                {
                    int mid = lb + (ub-lb)/2;
                    if(isValid(sweetness, sweetness.size(), k+1, mid))
                    {
                        res = mid;
                        lb = mid+1;
                    }
                    else
                    {
                        ub = mid-1;
                    }
                }
                return res;
        }
};
