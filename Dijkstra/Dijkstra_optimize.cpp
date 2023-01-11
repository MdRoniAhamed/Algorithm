#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int N = 1e5;
int visited[N + 5], parent[N + 5];
int d[N + 5];
int nodes, edges;
vector<pair<int, int>> adj_list[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        auto head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if (visited[selected_node])
            continue;
        visited[selected_node] = 1;
        for (auto adj_entry : adj_list[selected_node])
        {
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;
            if (d[selected_node] + edge_cst < d[adj_node])
            {
                parent[adj_node] = selected_node;
                d[adj_node] = d[selected_node] + edge_cst;
                pq.push({d[adj_node], adj_node});
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

    int current_node = nodes;
    stack<int> path;
    while (true)
    {
        path.push(current_node);
        if (current_node == src)
            break;
        current_node = parent[current_node];
    }

    cout<<"Shorted path: \n";
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }

    cout << "\n";

    return 0;
}
