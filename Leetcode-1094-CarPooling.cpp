class Solution 
{
    public:

        static bool cmp1(vector<int> a, vector<int> b)
        {
            return a[1] < b[1];
        }

        static bool cmp2(vector<int> a, vector<int> b)
        {
            return a[2] < b[2];
        }
        
        bool carPooling(vector<vector<int>> &trips, int cap) 
        {
            vector<vector<int>> arr = trips, dep = trips;
            sort(arr.begin(), arr.end(), cmp1);
            sort(dep.begin(), dep.end(), cmp2);
            int n = trips.size(), i = 0, j = 1;
            cap -= arr[0][0];
            while(i < n && j < n)
            {
                if(cap < 0)
                {
                    return false;
                }
                if(dep[i][2] > arr[j][1])
                {
                    cap -= arr[j][0];
                    j++;
                }
                else
                {
                    cap += dep[i][0];
                    i++;
                }
            }
            return cap >= 0;
        }
};
