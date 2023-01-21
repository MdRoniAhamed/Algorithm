#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int d[N][N]; // Distance 2D Array make
const int INF = INT_MAX;

int main()
{
    int n, m; // n = nodes , m = edges
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[N][N] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    cout<<endl;
}