///uva 280 vertex
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
bool visited[101];
int sol;

void dfs(int start)
{
    for(int i=0; i<adj[start].size(); i++)
    {
        int v = adj[start][i];

        if(!visited[v]){
            visited[v] = true;
            sol++;
            dfs(v);
        }
    }
}

/*void dfs(int start)
{
    if(visited[start] == true)
        return;

    visited[start] = true;

    for(int i=0; i<adj[start].size(); i++){
        dfs( adj[start][i] );
    }
}*/

int main()
{
    //freopen("in.txt", "r", stdin);
    //
    freopen("out.txt", "w", stdout);

    int n;
    while(cin>>n && n){
        for(int i=0; i<=n; i++)
            adj[i].clear();

        int parent;
        while(cin>>parent && parent){
            int child;
            while(cin>>child && child){
                adj[parent].push_back(child);
            }
        }
        int t;  cin>>t;
        while(t--)
        {
            int start;
            cin>>start;

            memset(visited, false, sizeof(visited));
            sol = 0;
            dfs(start);

            /*for(int i=1; i<=n; i++){
                if(!visited[i])
                    sol++;
            }
            cout<<sol;*/
            cout<<n-sol;
            for(int i=1; i<=n; i++){
                if(!visited[i])
                    cout<<" "<<i;
            }
            printf("\n");
        }
    }
    return 0;
}
