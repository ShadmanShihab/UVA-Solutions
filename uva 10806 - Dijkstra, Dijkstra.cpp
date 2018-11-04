//uva 10806 - Dijkstra, Dijkstra.
#include <bits/stdc++.h>
using namespace std;

#define Max 105
#define pii pair <int, int>
const int INF = 2000000000;

vector<pii> adj[Max];
bool used[Max][Max];
int dis[Max],from[Max], n;

void dijkstra(int start, int des)
{
    for(int i=0; i<n; i++)
        dis[i] = INF;

    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push( pii(start, 0));
    dis[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().first;
        int c = pq.top().second;
        pq.pop();

        if(u == des)
            break;
        if(dis[u] < c)
            continue;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(!used[u][v])
            {
                if(dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    from[v] = u;
                    pq.push( pii(v, dis[v]));
                }
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            for (int j = 0; j < n; ++j) {
                used[i][j] = false;
            }
        }
        if(n == 0)
            break;

        int e;
        scanf("%d", &e);
        for(int i=0; i<e; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            x--;
            y--;
            adj[x].push_back( pii(y, z) );
            adj[y].push_back( pii(x, z) );
        }

        dijkstra(0, n-1);
        if(dis[n-1] == INF)
        {
            printf("Back to jail\n");
            continue;
        }
        int res = dis[n-1];

        int temp = n - 1;
        while(temp != 0)
        {
            used[from[temp]][temp] = true;

            for (int k = 0; k < adj[temp].size(); k++) {
                int v = adj[temp][k].first;
                //int m = adj[temp][k].second;

                if (v != from[temp]) continue;

                adj[temp][k].second *= -1;
            }
            temp = from[temp];
        }

        dijkstra(0, n-1);
        if(dis[n-1] == INF)
        {
            printf("Back to jail\n");
            continue;
        }
        res += dis[n-1];
        cout<<res<<endl;
        memset(from, 0, sizeof(from));
    }
    return 0;
}
