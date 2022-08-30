class Solution 
{
    public:
        int solve(string s, int k, char c)  // Longest substring with at most k number of c
        {
            int i = 0, j = 0, n = s.size(), cnt = 0, ans = 0;
            while(j < n)
            {
                if(s[j] == c)
                {
                    cnt++;
                }
                while(cnt > k)
                {
                    if(s[i] == c)
                    {
                        cnt--;
                    }
                    i++;
                }
                ans = max(ans, j-i+1);
                j++;
            }
            return ans;
        }
        int maxConsecutiveAnswers(string answerKey, int k) 
        {
            return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
        }
};
