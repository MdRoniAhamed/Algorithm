/* #include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
vector<pair<int, int>> adj_list[N];
int d[N], visited[N];
int nodes, edges;

void dijkstra(int src)
{
    for (int i = 0; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int selected = -1;
        for (int j = 1; j < nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            if (selected == -1 || d[selected] > d[j])
            {
                selected = j;
            }
        }
        visited[selected] = 1;
        for (auto adj_entry : adj_list[selected])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            if (d[selected] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected] + edge_cst;
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    return 0;
} */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e9;
int d[N], visited[N];
int nodes, edges;
vector<pair<int, int>> adj_list[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int node = -1;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            if (node == -1 || d[node] > d[j])
            {
                node = j;
            }
        }
        visited[node] = 1;
        for(auto adj_entry : adj_list[node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            if(d[node] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[node] + edge_cst;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

/* 
6 8
1 2 4
1 3 4
2 3 2
3 4 1
3 5 3
3 6 6
5 6 2
4 6 3
 */