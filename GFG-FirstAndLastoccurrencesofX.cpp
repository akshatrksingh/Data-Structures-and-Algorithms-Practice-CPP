vector<int> find(int arr[], int n , int x)
{
    vector<int> v, w;
    for(int i = 0; i < n; i++) 
    {
        v.push_back(arr[i]);
    }
    if(!binary_search(v.begin(), v.end(), x)) return {-1, -1};
    w.push_back(lower_bound(v.begin(), v.end(), x)-v.begin());
    w.push_back(upper_bound(v.begin(), v.end(), x)-v.begin()-1);
    return w;
}
