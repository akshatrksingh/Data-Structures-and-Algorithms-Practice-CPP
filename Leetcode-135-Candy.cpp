class Solution
{
    public:
        int candy(vector<int>& ratings) 
        {
            int n = ratings.size();
            vector<int> candies(n, 1);
            for(int i = 1; i <= n-1; i++)
            {
                if(ratings[i] > ratings[i-1])
                {
                    candies[i] = candies[i-1]+1;
                }
            }
            for(int i = n-2; i >= 0; i--)
            {
                if(ratings[i] > ratings[i+1])
                {
                    candies[i] = max(candies[i], candies[i+1]+1);
                    /*
                    During the right-to-left pass, we compare the rating of the current child with                     their right neighbor. If the current child has a higher rating, we want to                         assign them more candies than their right neighbor. However, we have already                       assigned candies to the children during the left-to-right pass, and some                           children may have already received more candies than their right neighbor.
                    */
                }
            }
            int sum = 0;
            for(int i = 0; i <= n-1; i++)
            {
                sum += candies[i];
            }
            return sum;
        }
};
