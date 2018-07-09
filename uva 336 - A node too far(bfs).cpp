 #include<bits/stdc++.h>
using namespace std;

map<int, int> visited;

void bfs(int start,map <int,vector<int> > adj)
{
    int u, v, size;

    visited.clear();

    queue<int> Q;
    Q.push(start);
    visited[start] = 0;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        size = adj[u].size();

        for(int i=0; i<size; i++){
            v = adj[u][i];
            if(!visited.count(v)){
                visited[v] = visited[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n,x,y,i,start,ttl,res,count=0;
    //vector<int> adj[100];

    while(1){
    map <int,vector<int> > adj;
        scanf("%d", &n);
        if(n==0)
            break;
        for(i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

    while(1)
    {
        map <int,int> ::iterator it;
        res = 0;
        scanf("%d %d", &start, &ttl);

        if(start == 0 && ttl == 0)
            break;

        count++;
        bfs(start, adj);

        for(it = visited.begin(); it != visited.end(); ++it){
                   if((*it).second>ttl)
                    ++res;
                 }
        res += adj.size()-visited.size();
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",count,res,start,ttl);
        }
    }
    return 0;
}
