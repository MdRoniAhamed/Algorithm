#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];
vector<int> adj_list[N];

void dfs(int node)
{
    cout<<node <<endl;
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }

}

/*
6 8

0 1
1 1
2 2
1 2
2 3
1 5
2 4
5 4

6 5

0 1
2 3
1 5
2 4
5 4
 */
int main()
{
    int node, edges;
     scanf("%d %d",&node,&edges);
//    cin>>node>>edges;
    for(int i=0; i<edges; i++)
    {
        int u,v;
         scanf("%d %d",&u,&v);
//        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


    int src = 1;
    dfs(src);
    return 0;
}
