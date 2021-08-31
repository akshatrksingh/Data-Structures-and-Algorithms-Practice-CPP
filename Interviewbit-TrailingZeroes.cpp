int Solution::solve(int num) 
{
    int cnt = 0;
    for (int i = 0; i <= 31; i++) 
    {
        if((num)&(1<<i))
        {
            return cnt;
        }
        else
        {
           cnt++;
        }
    }
}
