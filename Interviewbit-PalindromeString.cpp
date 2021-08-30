int Solution::isPalindrome(string s) 
{
    string x;
    int c = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(isalnum(s[i]))
        {
            x.push_back(tolower(s[i]));
        }
    }
    for(int i = 0; i < x.size()/2; i++)
    {
        if(x[i] != x[x.size()-i-1])
        {
            return 0;
        }
    }
    return 1;
}
