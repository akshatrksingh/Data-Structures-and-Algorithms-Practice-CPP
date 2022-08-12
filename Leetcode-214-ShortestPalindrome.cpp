/*
Here we are not computing the prefix function for using the KMP algorithm
Instead, we use it to get the length largest palindromic substring starting at the 0th index
Example: catacb
Temp String: catacb#bcatac
KMP table:
c a t a c b # b c a t a c
0 0 0 0 1 0 0 0 1 2 3 4 5
In the last cell, we got a value 5. It means in s we have a substring of length 5 that is palindrome.
Thus pi.back() give us the required length
Now the characters to be added to thr front are basically the reverse of the left out string if we remove the palindomic substring starting at the 0th index
*/
class Solution 
{
    public:
        vector<int> compute_pi(string s) 
        {
            int n = s.length();
            vector<int> pi(n);
            pi[0] = 0;
            for (int i = 1; i < n; i++) 
            {
                int j = pi[i-1]; 
                while (j > 0 && s[j] != s[i]) 
                {
                    j = pi[j-1];
                }
                if (s[j] == s[i]) 
                {
                    pi[i] = j+1;
                }   
                else
                {
                    pi[i] = 0;
                }
            }
            return pi;
        }
        string shortestPalindrome(string s) 
        {
            string rev = s;
            reverse(rev.begin(), rev.end());
            vector<int> pi = compute_pi(s+'#'+rev);
            string front = s.substr(pi.back());
            reverse(front.begin(), front.end());
            return front+s;
        }
};
