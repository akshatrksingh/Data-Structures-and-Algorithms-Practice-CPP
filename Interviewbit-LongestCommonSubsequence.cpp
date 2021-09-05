int Solution::solve(string s1, string s2) 
{
    int n1 = s1.size()+1;
    int n2 = s2.size()+1;
    int s[n1][n2];
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(i == 0 || j ==0)
            {
                s[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                s[i][j] = s[i-1][j-1] + 1; 
            }
            else
            {
                s[i][j] = max(s[i][j-1], s[i-1][j]);
            }
        }
    }
    return s[n1-1][n2-1];
}
