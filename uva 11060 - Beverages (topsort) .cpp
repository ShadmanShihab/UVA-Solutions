///uva 11060 - Beverages
///topsort
#include <bits/stdc++.h>
using namespace std;

int indegree[102] = {};
vector<int> adj[102];
string names[105];

void topsort(int n)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            pq.push(i);

    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        cout<<" "<<names[u];

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                pq.push(v);
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    map<string, int> beverages;
    map<string, int>::iterator it;

    int n, m;
    int kase = 0;
    while(scanf("%d", &n) == 1)
    {
        kase++;
        memset(indegree, 0, sizeof(indegree));
        memset(adj, 0, sizeof(adj));
        memset(names, 0, sizeof(names));
        beverages.clear();

        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            beverages[str] = i;
            names[i] = str;
        }
        scanf("%d", &m);
        for(int i=1; i<=m; i++)
        {
            string s1, s2;
            cin>>s1>>s2;
            indegree[beverages[s2]]++;
            adj[beverages[s1]].push_back( beverages[s2] );
        }

        /*for(int i=1; i<=n; i++)
            cout<<i<<" -> "<<indegree[i]<<endl;

        for(int i=1; i<=n; i++)
        {
            cout<<i<<" -> ";
            for(int j=0; j<adj[i].size(); j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }*/
        printf("Case #%d: Dilbert should drink beverages in this order:", kase);
        topsort(n);
        printf(".\n\n");
    }
    return 0;
}
