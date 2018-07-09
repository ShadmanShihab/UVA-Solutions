///uva 10986 Sending email
///dijkstra
#include <bits/stdc++.h>
using namespace std;
#define max 20010
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
int infinity = 1000000000;
vector <pii> adj[max];
int dis[max];

void dijkstra(int start)
{
    priority_queue <pii, vector<pii>, greater<pii> > pq;

    pq.push( pii(start, 0) );
    dis[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().first;
        int c = pq.top().second;
        pq.pop();

        if(dis[u] < c)
            continue;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push( pii(v, dis[v]) );
            }
        }
    }
}
int main()
{
    int T, n, m, s, t;
    scanf("%d", &T);

    for(int i=1; i<=T; i++)
    {
        memset(adj, 0, sizeof(adj));
        //memset(dis, inf, sizeof(dis));
        scanf("%d %d %d %d", &n, &m, &s, &t);

        for(int i=0; i<=n; i++)
            dis[i] = infinity;

        for(int k=0; k<m; k++)
        {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back( pii(y, w) );
            adj[y].push_back( pii(x, w) );
        }

        dijkstra(s);

        if(dis[t] == infinity)
            printf("Case #%d: unreachable\n", i);
        else
            printf("Case #%d: %d\n", i, dis[t]);
    }
    return 0;
}
