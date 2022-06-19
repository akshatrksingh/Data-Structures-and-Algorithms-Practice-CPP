vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) 
{
    long long int i = 0, j = 0;
    vector<long long int> v;
    list<long long int> l;
    while(j < n)
    {
        if(arr[j] < 0)
        {
            l.push_back(arr[j]);
        }
        if(j-i+1 < k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(l.size() == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if(arr[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return v;
}
