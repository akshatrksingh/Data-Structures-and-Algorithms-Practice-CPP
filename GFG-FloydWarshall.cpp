class Solution 
{
  public:
	void shortest_distance(vector<vector<int>> &matrix)
	{
	    const int INF = 1e8; // INF = 100M, not 2^31-1 to avoid overflow
	    int V = matrix.size();
	    for(int i = 0; i < V; i++)
	    {
	        for(int j = 0; j < V; j++)
	        {
	            if(matrix[i][j] == -1)
	            {
	                matrix[i][j] = INF;
	            }
	        }
	    }
	    for(int k = 0; k < V; k++)
	    {
	        for(int i = 0; i < V; i++)
	        {
	            for(int j = 0; j < V; j++)
	            {
	                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    for(int i = 0; i < V; i++)
	    {
	        for(int j = 0; j < V; j++)
	        {
	            if(matrix[i][j] == INF)
	            {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};
