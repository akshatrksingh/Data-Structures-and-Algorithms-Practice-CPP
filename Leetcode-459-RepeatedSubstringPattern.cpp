/*
We can use the logic that such a string would be equal to some rotation of itself
We can iterate through such rotations by appending the string to itself then moving a sliding winodw of length equal to the string
Ignore the first and the last character
class Solution 
{
    public:
        bool repeatedSubstringPattern(string s) 
        {
            string S = s + s;
            S = S.substr(1, S.size() - 2);
            return S.find(s) == string::npos ? false:true;
        }
};
*/
class Solution 
{
    public:
        bool repeatedSubstringPattern(string s) 
        {
            int n = s.size();
            if(n <= 1)
            {
                return false;
            }
            string tmp, sub;
            for(int i = 0; i < n/2; i++)
            {
                tmp = "";
                if(n % (i+1) == 0)
                {
                    sub =  s.substr(0, i+1);
                    for(int j = 0; j < n/(i+1); j++)
                    {
                        tmp += sub;
                    }
                    if(tmp == s)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};
