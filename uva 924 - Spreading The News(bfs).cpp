//uva 924 - Spreading The News
#include <bits/stdc++.h>
using namespace std;

#define Max 2505
vector<int> adj[Max];
bool visited[Max];
int level[Max];

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

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if(!visited[v])
            {
                visited[v] = true;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int E;
    while(scanf("%d", &E) == 1)
    {
        memset(adj, 0, sizeof(adj));
        for(int i=0; i<E; i++)
        {
            int n, temp;
            scanf("%d", &n);

            for(int j=0; j<n; j++)
            {
                scanf("%d", &temp);
                adj[i].push_back(temp);
            }
        }

        int T, start;
        scanf("%d", &T);
        while(T--)
        {
            scanf("%d", &start);

            bfs(start);

            int ara[Max];
            memset(ara, 0, sizeof(ara));
            int boomSize = -1, boomday = 0;


            for(int i=0; i<E; i++)
            {
                if(level[i] != 0)
                    ara[level[i]]++;
            }


            for(int i=0; i<E; i++)
            {
                if(boomSize < ara[i])
                {
                    boomSize = ara[i];
                    boomday = i;
                }
            }

            if(boomSize == 0)
                printf("0\n");
            else
                printf("%d %d\n", boomSize, boomday);
        }
    }
    return 0;
}
