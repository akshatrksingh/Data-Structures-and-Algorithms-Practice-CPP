class Solution 
{
    public:

        void dfs(string node, string& dest, unordered_map<string, unordered_map<string, double>>& gr, unordered_set<string>& vis, double& ans, double temp) 
        {
            if(vis.find(node) != vis.end()) 
            {
                return;
            }

            vis.insert(node);
            
            if(node == dest)
            {
                ans = temp;
                return;
            }

            for(auto nbr: gr[node])
            {
                dfs(nbr.first, dest, gr, vis, ans, temp * nbr.second);
            }
        }

        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
        {
            unordered_map<string, unordered_map<string, double>> gr;

            for (int i = 0; i < equations.size(); i++) 
            {
                string dividend = equations[i][0];
                string divisor = equations[i][1];
                double value = values[i];

                gr[dividend][divisor] = value;
                gr[divisor][dividend] = 1.0 / value;
            }
            
            vector<double> finalAns;

            for (auto query : queries) 
            {
                string dividend = query[0];
                string divisor = query[1];

                if (gr.find(dividend) == gr.end()) 
                {
                    finalAns.push_back(-1.0);
                } 
                else 
                {
                    unordered_set<string> vis;
                    double ans = -1, temp = 1.0;
                    dfs(dividend, divisor, gr, vis, ans, temp);
                    finalAns.push_back(ans);
                }
            }

            return finalAns;
        }
};
