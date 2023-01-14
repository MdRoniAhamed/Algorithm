#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9;
vector<vector<int>> graph;
vector<int> dis(N, INF);
vector<int> vis(N, 0);
void BellmanFord(int src, int V, int E) 
{
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int wt = graph[j][2];
            if (dis[u] != INT_MAX && dis[u] + wt <dis[v])
                dis[v] = min(dis[v], dis[u] + wt);

        }
    }
    for (int i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl;
    }

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
} 
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u,v, w});
    }
    BellmanFord(0, v, e);
    return 0;
}

// 5 8
// 1 2 3
// 3 2 5
// 1 3 2
// 3 1 1
// 1 4 2
// 0 2 4
// 4 3 -3
// 0 1 -1

// Vertex Distance from Source
// 0               0
// 1               -1
// 2               2
// 3               -2
// 4               1