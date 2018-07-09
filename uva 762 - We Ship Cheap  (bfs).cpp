#include <bits/stdc++.h>
using namespace std;

map <string, string> parent;
map <string, int> level;

int bfs(string s,string e, map <string, vector<string> > adj)
{
    queue<string> Q;
    Q.push(s);
    level[s] = 1;

    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        if(u == e)
            return level[u];

        for(int i=0; i<adj[u].size(); i++){
            string v = adj[u][i];

            if(level[v] == -1){
                level[v] = level[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
    return -1;
}

void printPath(string s, string e)
{
    if(s == e)
        return;

    printPath(parent[s], e);
    cout<<parent[s]<<" "<<e<<endl;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    bool flag = false;

    while(scanf("%d", &n) == 1){
        map <string, vector<string> > adj;

        for(int i=0; i<n; i++){
            string x, y;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);

            level[x] = -1;
            level[y] = -1;
        }

        string s, e;
        cin>>s>>e;

        if(flag)
            printf ("\n");
        flag = true;

        int a = bfs(s, e, adj);

        if(a == -1)
            printf("No route\n");
        else
            printPath(e, s);
    }
    return 0;
}
