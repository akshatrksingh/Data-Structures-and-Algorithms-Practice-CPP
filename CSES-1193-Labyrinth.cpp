#include <bits/stdc++.h>
using namespace std;

void labyrinth(string grid[], int n, int m)
{
    bool vis[n][m];
    int previousStep[n][m];
    pair<int, int> beg, end;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            if(grid[i].at(j) == 'A')
            {
                beg = make_pair(i, j);
            }
            else if(grid[i].at(j) == 'B')
            {
                end = make_pair(i, j);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(beg);
    vis[beg.first][beg.second] = true;
    //Not the typical x-y plane
    /*
    y - right
    x - down
    */
    // Right, Left, Down, Up
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    string stepDir = "RLDU";
    int x, y;

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            x = t.first + dx[i];
            y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && grid[x].at(y) != '#' && !vis[x][y]) 
            {
                vis[x][y] = true;
                previousStep[x][y] = i;
                q.push({x, y});
            }
        }
    }

    if(vis[end.first][end.second])
    {
        cout<<"YES"<<endl;
        list<int> steps;
        while(end != beg)
        {
            x = end.first;
            y = end.second;
            int p = previousStep[x][y];
            steps.push_front(p);
            end = make_pair(x-dx[p], y-dy[p]);
        }
        cout<<steps.size()<<endl;
        for (char c : steps) 
        {
			cout<<stepDir[c];
		}
		cout << endl;
    }
    else
    {
        cout<<"NO";
    }
}

int main()
{
    int n, m;
    cin>>n>>m; 
    string grid[n];
    for(int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        grid[i] = s;
    }
    labyrinth(grid, n, m);
	return 0;
}