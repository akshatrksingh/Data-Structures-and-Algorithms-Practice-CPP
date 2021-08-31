int Solution::titleToNumber(string s) 
{
    int a, num, c = 0;
    for(auto it = s.end()-1; it >= s.begin(); it--)
    {
        a = *it-'A'+1;
        num += (int)pow(26, c++)*a;
    }
    return num;
}

