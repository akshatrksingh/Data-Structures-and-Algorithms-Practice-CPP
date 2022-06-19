class Solution 
{
    public:
        vector<int> factorial(int n)
        {
            vector<int> fact;
            fact.push_back(1);
            for(int i = 2; i <= n; i++)
            {
                int carry = 0;
                for(int j = fact.size()-1; j >= 0; j--)
                {
                    int prod = fact[j]*i+carry;
                    fact[j] = prod%10;
                    carry = prod/10;
                }
                reverse(fact.begin(), fact.end());
                while(carry != 0)
                {
                    fact.push_back(carry%10);
                    carry /= 10;
                }
                reverse(fact.begin(), fact.end());
            }
            return fact;
        }
};
