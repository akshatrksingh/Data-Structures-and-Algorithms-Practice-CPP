int Solution::solve(vector<int> &V, vector<int> &W, int wc) 
{
    int n = V.size(), x;
    int arr[n+1][wc+1];
    for(int i = 0; i < n+1; i ++)
    {
        for(int w = 0; w < wc+1; w++)
        {
            if(i == 0 || w == 0)
            {
                arr[i][w] = 0;
            }
            else if(W[i-1] <= w)
            {
                arr[i][w] = max(arr[i-1][w], arr[i-1][w-W[i-1]]+V[i-1]);
            }
            else
            {
                arr[i][w] = arr[i-1][w];
            }
        }
    }
    return arr[n][wc];
}
