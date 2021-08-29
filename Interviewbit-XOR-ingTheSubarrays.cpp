int Solution::solve(vector<int> &v) 
{
    int x;
    for(int i = 0; i < v.size(); i++)
    {
        if((i+1)*(v.size()-i) % 2 != 0)  //each element will contribute to (i+1)*(v.size()-1) contiguous subarrays
            x ^= v[i];
    }
    return x;
}
