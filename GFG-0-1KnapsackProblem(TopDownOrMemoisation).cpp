class Solution
{
    public:                   
        int solve(int item, int wt_left, int wt[], int val[]) 
        {
            if(item < 0 || wt_left == 0)
                return 0;
            if(wt[item] <= wt_left)    // CHOOSE THE ITEM AT INDEX
                return max(val[item] + solve(item-1, wt_left-wt[item], wt, val),
                           solve(item-1, wt_left, wt, val));
            else                        // DO NOT CHOOSE THE ITEM AT INDEX
                return solve(item-1, wt_left, wt, val);
            
        }                       
        int knapSack(int w, int wt[], int val[], int n) 
        {
            return solve(n-1, w, wt, val);
        }
};
