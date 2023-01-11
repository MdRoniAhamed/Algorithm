#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int Level[N];
vector<int> adj_list[N];
void bfs(int scr){
    queue<int> q;
    q.push(scr);
    Level[scr] = 0; 
    while(!q.empty()){
        int head = q.front();
        q.pop();
        visited[head] = 1;
        for(int adj_node: adj_list[head]){
            if(visited[adj_node]==0){
                visited[adj_node] = 1;
                Level[adj_node] = Level[head] +1;
                q.push(adj_node);
            }
        }
    }
}
int main(){
    int nodes,edges;
    scanf("%d%d",&nodes,&edges);

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 0;
    bfs(src);

    for(int i=0; i<nodes; i++){
        cout<<"Nodes "<<i<<" -> Level: "<<Level[i]<<endl;
    }


    return 0;
}

/* 

6 6


0 1
2 3
1 5
1 2
2 4
5 4

 */