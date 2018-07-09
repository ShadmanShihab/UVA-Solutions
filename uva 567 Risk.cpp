///uva 567 Risk
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[50];
bool visited[50];
int level[50];

void bfs(int start)
{
    memset(visited, false, sizeof(visited));
    memset(level, 0, sizeof(level));

    queue<int> Q;
    Q.push(start);
    visited[start] = true;
    level[start] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];

            if(visited[v] == false){
                visited[v] = true;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n, x, y, z, kase=0;

    while(scanf("%d",&n)==1)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&x);
            adj[1].push_back(x);
            adj[x].push_back(1);
        }
        for(int i=2; i<=19; i++)
        {
            scanf("%d",&y);
            for(int j=0; j<y; j++)
            {
                scanf("%d",&z);
                adj[i].push_back(z);
                adj[z].push_back(i);
            }
        }
        int start, des, T;
        scanf("%d",&T);
        printf("Test Set #%d\n",++kase);
        for(int i=0; i<T; i++)
        {
            scanf("%d %d",&start, &des);
            bfs(start);
            printf("%2d to %2d: %d\n", start, des, level[des]);
        }
       printf("\n");
       for(int i=0; i<21; i++)
           adj[i].clear();
    }
    return 0;
}
