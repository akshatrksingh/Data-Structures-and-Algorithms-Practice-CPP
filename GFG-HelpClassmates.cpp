class Solution
{
    
    public:
    vector<int> help_classmate(vector<int> A, int n) 
    {
        reverse(A.begin(), A.end());
        stack<int> s;
        vector<int> N; // to store the next smaller elements
        int min = INT_MAX;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] <= min)
            {
                min = A[i];
                N.push_back(-1);
            }
            while(!s.empty())
            {
                if(s.top() < A[i])
                {
                    N.push_back(s.top());
                    break;
                }
                s.pop();
            }
            s.push(A[i]);
        }
        reverse(N.begin(), N.end());
        return N;
    } 
};
