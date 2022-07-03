class Solution 
{
    public:
        int kthSmallest(vector<vector<int>>& mat, int k) 
        {
            priority_queue<int> maxHeap;
            for(int i = 0; i < mat.size(); i++)               
            {
                for(int j = 0; j < mat[i].size(); j++)       
                {
                    maxHeap.push(mat[i][j]);         
                    if(maxHeap.size() > k)
                        maxHeap.pop();            
                }                                 
            }       
            //TC: O(R*C log k)
            return maxHeap.top();
        }
};
