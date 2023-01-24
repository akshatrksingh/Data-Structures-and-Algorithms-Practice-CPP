/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    
        static bool cmp(Job a, Job b)
        {
            return a.profit > b.profit;
        }
        
        vector<int> JobScheduling(Job arr[], int n) 
        { 
            sort(arr, arr+n, cmp);
            vector<int> slot(n, -1);
            int cnt = 0, prof = 0;
            for(int i = 0; i < n; i++)
            {
                for (int j = min(n, arr[i].dead)-1; j >= 0; j--) 
                {
                    if(slot[j] == -1)
                    {
                        cnt++;
                        slot[j] = i;
                        prof += arr[i].profit;
                        break;
                    }
                }
            }
            vector<int> ans(2);
            ans[0] = cnt;
            ans[1] = prof;
            return ans;
        }
        // TC: O(N^2) 
};

