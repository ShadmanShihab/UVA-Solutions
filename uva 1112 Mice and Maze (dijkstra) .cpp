///uva 1112 Mice and Maze
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define sc scanf
#define pf printf
#define pii pair<int, int>

const int INF = 0x3f3f3f3f;

vector<pii> adj[110];
int dis[110];

void dijkstra(int start)
{
    priority_queue < pii, vector<pii>, greater<pii> > pq;
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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int kase, n, e, w, T, M, c=0;
    sc("%d", &kase);
    while(kase--)
    {
        if(c == 1)
            printf("\n");
        c = 0;
        memset(dis, INF, sizeof(dis));
        memset(adj, 0, sizeof(adj));

        sc("%d", &n);
        sc("%d", &e);
        sc("%d", &T);
        sc("%d", &M);
        while(M--)
        {
            int a, b, w;
            sc("%d %d %d", &a, &b, &w);

            adj[b].push_back( pii(a, w) );  //mice can travel from a to b
                                            //cant travel from b to a
        }

        dijkstra(e);

        int count = 0;

        for(int i=1; i<=n; i++)
        {
            if(dis>0 && dis[i] <= T)
                count++;
        }

        pf("%d\n", count);
        c = 1;
    }
    return 0;
}
