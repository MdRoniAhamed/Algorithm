#include<bits/stdc++.h>
#define pub push_back
using namespace std;

void solve(){
    int nodes,edge;
    scanf("%d%d",&nodes,&edge);
    vector<int> v[nodes];
    while(edge--){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pub(y);
        v[y].pub(x);
    }
}

int main(){
    solve();

    return 0;
}

// 1 hour :1 minute video dekse
