///uva 558 wormholes
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
vector<pii> adj[1010];
int inf = 10000000;
int dis[1010];
int n, m;

void BellmanFord(int start)
{
    for(int i=0; i<=n; i++)
        dis[i] = inf;

    dis[start] = 0;

    for(int i=0; i<n-1; i++)
    {
        for(int u=0; u<n; u++)
        {
            for(int v = 0; v<adj[u].size(); v++)
            {
                //cout<<dis[adj[u][v].first]<<" "<<dis[u]<<"+"<<adj[u][v].second<<endl;
                if(dis[adj[u][v].first] > dis[u] + adj[u][v].second){
                    dis[adj[u][v].first] = dis[u] + adj[u][v].second;
                    //cout<<"new = "<<adj[u][v].first<<" ->"<<dis[adj[u][v].first]<<endl;
                }
            }
        }
    }
    bool flag = false;
    for(int u=0; u<n; u++)
    {
        for(int v = 0; v<adj[u].size(); v++)
        {
            if(dis[adj[u][v].first] > dis[u] + adj[u][v].second){
                //cout<<dis[adj[u][v].first]<<" "<<dis[u]<<"+"<<adj[u][v].second<<endl;
                flag = true;
            }
        }
    }

    if(flag == true)
        printf("possible\n");
    else
        printf("not possible\n");
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);

        for(int i=0; i<=n; i++)
            adj[i].clear();

        for(int i=0; i<m; i++)
        {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back( pii(y,w) );
        }
        BellmanFord(0);
    }
    return 0;
}
