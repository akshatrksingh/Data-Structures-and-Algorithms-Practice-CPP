class Solution 
{
    public:
        char nextGreatestLetter(vector<char> &letters, char target) 
        {
            int n = letters.size();
            int lb = 0, ub = n-1, mid;
            int ans = INT_MAX;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(letters[mid] > target)
                {
                    ans = min(ans, mid);
                }
                if(letters[mid] <= target)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            return (ans == INT_MAX)? letters[0]: letters[ans];
        }
};
