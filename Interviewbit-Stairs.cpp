int Solution::climbStairs(int ns) 
{
    int arr[ns+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= ns; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[ns];
}
