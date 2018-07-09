///uva 10305 - Ordering Tasks
///topological sort using bfs
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int indegree[101] = {0};
bool visited[101] = {false};
int n;

void topSort()
{
    queue<int>Q;

    for(int i=1; i<=n; i++)
    {
        if(indegree[i] == 0){
            Q.push(i);
            //cout<<i<<"is pushed\n";
        }
    }

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        //visited[u] = true;
        printf("%d", u);

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            indegree[v]--;

            if(indegree[v] == 0)
                Q.push(v);
        }
        if(!Q.empty())
            printf(" ");
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int m;

    while(1)
    {
        scanf("%d %d", &n, &m);

        if(n==0 && m==0) break;

        for(int i=1; i<=m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            adj[x].push_back(y);
            indegree[y]++;
        }
        topSort();

        memset(adj, 0, sizeof(adj));
        //memset(visited, false, sizeof(visited));
        memset(indegree, 0, sizeof(indegree));
    }
    return 0;
}
