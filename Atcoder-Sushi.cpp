#include <bits/stdc++.h>
using namespace std;

const int mx = 305;
double p[mx][mx][mx];   // prob to get to state (a, b, c)
double ev[mx][mx][mx];  // expected val of # of operations to get to state (a, b, c)

void solve(vector<int> &cnt, int n)
{
    p[cnt[1]][cnt[2]][cnt[3]] = 1;
    for(int c = n; c >= 0; c--)
    {
        for(int b = n; b >= 0; b--)
        {
            for(int a = n; a >= 0; a--)
            {
                if(a+b+c > n)
                    continue;
                else if(a == 0 && b == 0 && c == 0)
                    continue;

                double p_waste = (double) (n-(a+b+c))/n;
                /*
                p_waste + p_waste^2 + .... = S
                p_waste (1 + S) = S
                p_waste + p_waste * S = S
                p_waste = S * (1 - p_waste)
                S = p_waste / (1 - p_waste)
                */
                double ev_waste = p_waste/(1-p_waste);
                ev[a][b][c] += ev_waste*p[a][b][c];

                // remove 1
                if(a != 0)
                {
                    double p_go = (double) a/(a+b+c);
                    p[a-1][b][c] += p[a][b][c]*p_go;
                    ev[a-1][b][c] += ev[a][b][c]*p_go;
                }

                // remove 2
                if(b != 0)
                {
                    double p_go = (double) b/(a+b+c);
                    p[a+1][b-1][c] += p[a][b][c]*p_go;
                    ev[a+1][b-1][c] += ev[a][b][c]*p_go;
                }

                // remove 1
                if(c != 0)
                {
                    double p_go = (double) c/(a+b+c);
                    p[a][b+1][c-1] += p[a][b][c]*p_go;
                    ev[a][b+1][c-1] += ev[a][b][c]*p_go;
                }
            }
        }
    }
    cout<<setprecision(10)<<ev[0][0][0]+cnt[1]+2*cnt[2]+3*cnt[3]<<"\n";
}         

int main()
{
    int n;
    cin>>n;
    vector<int> cnt(4);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin>>x;
        ++cnt[x];
    }
    solve(cnt, n);
    return 0;
}