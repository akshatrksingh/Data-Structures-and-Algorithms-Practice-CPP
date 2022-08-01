#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<vector<int>> g;
vector<vector<int>> previousStep;
vector<pair<int, int>> monster;
pair<int, int> beg, esc; 
vector<pair<int,int>> moves = {{0, 1},{0, -1},{1, 0},{-1, 0}}; 

bool isExcape(int x, int y, int timer)
{
    if(!(x >= 0 && x < n && y >= 0 && y < m && g[x][y] > timer))   // !(valid) => invalid 
    {
        return false;
    }
    if(x == 0 || y == 0 || x == n-1 || y == m-1) 
    {
        return true;
    }
    return false;
}
 
void bfs_escape()
{
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(beg, 0));
    
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    string stepDir = "RLDU";
    previousStep.resize(n, vector<int>(m));
    int x, y, timer;

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            x = t.first.first + dx[i];
            y = t.first.second + dy[i];
            timer = t.second;
            timer++;

            if(isExcape(x, y, timer))
            {
                previousStep[x][y] = i;
                esc = {x, y}; 
                list<int> steps;

                while(esc != beg)
                {
                    x = esc.first;
                    y = esc.second;
                    int p = previousStep[x][y];
                    steps.push_front(p);
                    esc = make_pair(x-dx[p], y-dy[p]);
                }
                cout<<"YES\n"<<steps.size()<<"\n";
                for (char c : steps) 
                {
                    cout<<stepDir[c];
                }
                cout<<"\n";
                return;
            }

            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] > timer)
            {
                previousStep[x][y] = i;
                g[x][y] = timer;
                q.push({{x, y}, timer});
            }
        }
    }
    cout<<"NO\n";
}

void preprocess_lava_flow()
{
    queue<pair<pair<int, int>, int>> q;
    for(auto m: monster)
    {
        q.push({m, 0});
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int x, y, timer;

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            x = t.first.first + dx[i];
            y = t.first.second + dy[i];
            timer = t.second;
            timer++;

            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] > timer)
            {
                g[x][y] = timer;
                q.push({{x, y}, timer});
            }
        }
    }
}

int main()
{
    cin>>n>>m; 
    string grid[n];
    g.resize(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        grid[i] = s;
    }
    
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(grid[i].at(j) == '#')
            {
                g[i][j] = 0;
            }
            else if(grid[i].at(j) == 'M')
            {
                g[i][j] = 0;
                monster.push_back({i, j});
            }
            else if(grid[i].at(j) == 'A')
            {
                g[i][j] = 0;
                beg = {i, j};
            }
            else
            {
                g[i][j] = INT_MAX;
            }
        }
    }  
 
    if(beg.first == 0 or beg.second == 0 or beg.first == n-1 or beg.second == m-1) 
    {
        cout<<"YES\n";
        cout<<0;
        return 0;
    }
   
    preprocess_lava_flow();
    bfs_escape();

    return 0;
}