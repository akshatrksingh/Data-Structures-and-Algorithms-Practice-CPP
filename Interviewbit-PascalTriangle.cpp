vector<vector<int>> Solution::solve(int v) 
{
    vector<vector<int>> VV;
    if(v == 0)
    {
        return VV;
    }
    vector<int> V;
    V.push_back(1);
    VV.push_back(V);
    if(v == 1)
    {
        return VV;
    }
    V.clear();
    V.push_back(1);
    V.push_back(1);
    VV.push_back(V);
    if(v == 2)
    {
        return VV;
    }
    int i, j;
    for(i = 2; i < v; i++)
    {
        vector<int> a(i+1, 0);
        VV.push_back(a);
        VV[i][0] = 1;
        for(j = 1; j < i; j++)
        {
            VV[i][j] = VV[i-1][j-1] + VV[i-1][j];
        }
        VV[i][j] = 1;
    }    
    return VV;
}
