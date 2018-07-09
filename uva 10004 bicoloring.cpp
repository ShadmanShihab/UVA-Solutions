#include <bits/stdc++.h>
using namespace std;
#define max 1000000

int visited[max];
vector<int> adj[max];

void bfs(int s, int n)
{
    memset(visited,-1,sizeof(visited));

    //for(int i=0; i<=n; i++)
        //visited[i] = -1;

    bool ret = true;
    int f=0;
    queue<int> Q;
    Q.push(0);
    visited[0] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
                int v = adj[u][i];

            if(visited[v] == -1){
                if(visited[u] == 0)
                    visited[adj[u][i]] = 1;
                else
                    visited[adj[u][i]] = 0;
                Q.push(v);
            }
            else{
                if(visited[u] == visited[adj[u][i]]){
                    ret = false;
                    break;
                }
            }
        }
    }
    if(ret)
        cout<<"BICOLORABLE.\n";
    else
        cout<<"NOT BICOLORABLE.\n";
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int N, E, x, y;
    while(1)
    {
        scanf("%d", &N);
        if(N == 0)
            break;
        scanf("%d", &E);

        for(int i=0; i<E; i++){
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(0, E);

        for(int i=0; i<=N; i++)
            adj[i].clear();
    }
    return 0;
}
