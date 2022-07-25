#include <bits/stdc++.h>
using namespace std;

void numRoomsRecursion(string grid[], int i, int j, int n, int m)
{
    if(i < 0 || j < 0 || i > n-1 || j > m-1 || grid[i][j] != '.')
    { 
        return;
    }
    if (grid[i][j] == '.')
    {
        grid[i][j] = 'V';  
        numRoomsRecursion(grid, i + 1, j, n, m);     
        numRoomsRecursion(grid, i - 1, j, n, m);     
        numRoomsRecursion(grid, i, j + 1, n, m);     
        numRoomsRecursion(grid, i, j - 1, n, m);     
    }
}

int numRooms(string grid[], int n, int m)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                grid[i][j] = 'V'; 
                cnt++;
                numRoomsRecursion(grid, i + 1, j, n, m);     
                numRoomsRecursion(grid, i - 1, j, n, m);     
                numRoomsRecursion(grid, i, j + 1, n, m);     
                numRoomsRecursion(grid, i, j - 1, n, m);    
            }
        }
    }
    return cnt;
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
    cout<<numRooms(grid, n, m);
	return 0;
}