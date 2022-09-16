class Solution 
{
    public:
        bool isValidSudoku(vector<vector<char>> &board) 
        {
            unordered_map <char, vector<pair<int, int>>> m;
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
                {
                    if(board[i][j] != '.')
                    {
                        m[board[i][j]].push_back({i, j});
                    }
                }
            }
            for(auto it = m.begin(); it != m.end(); it++)
            {
                vector<pair<int, int>> v = it->second;
                int n = v.size();
                for(int i = 0; i < n; i++)
                {
                    for(int j = i+1; j < n; j++)
                    {
                        if(v[i].first == v[j].first || v[i].second == v[j].second || (v[i].first/3 == v[j].first/3 && v[i].second/3 == v[j].second/3 ))
                        {
                            cout<<v[i].first<<v[j].first;
                            return 0;
                        }
                    }
                }
            }
            return 1;
        }
};
