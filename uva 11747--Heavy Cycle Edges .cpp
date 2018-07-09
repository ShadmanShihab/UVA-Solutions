///kruskal implementation
/// O(mlogm)
///uva 11747--Heavy Cycle Edges
#include <bits/stdc++.h>
using namespace std;
#define MAX 1020
int parent[MAX];

struct edge {
    int u, v, w;
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

vector<edge> V;
vector<int> weight;

int Find(int r)
{
    if(parent[r] == r)
        return r;
    return parent[r] = Find(parent[r]);
}

void makeSet(int n)
{
    for(int i=1; i<=n; i++)
        parent[i] = i;
}

int Union(int n)
{
    int Count = 0;
    int Size = V.size();

    for(int i=0; i<Size; i++)
    {
        int u = Find(V[i].u);
        int v = Find(V[i].v);

        if(u != v)
        {
            parent[v] = u;
            Count++;

            V[i].w = -1;

            if(Count == n-1)
                break;
        }
    }
}

int kruskal(int n)
{
    sort(V.begin(), V.end());

    makeSet(n);
    Union(n);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    while(1)
    {

        int n, m;
        scanf("%d %d", &n, &m);

        if(n==0 && m==0)
            break;

        for(int i=1; i<=m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            edge get;

            get.u = u;
            get.v = v;
            get.w = w;

            V.push_back(get);
        }
        kruskal(n);

        bool flag = false;
        bool space = false;

        for(int i=0; i<V.size(); i++){

            if(V[i].w != -1){

                if(space)
                    printf(" ");

                flag = true;
                cout<<V[i].w;

                space = true;
            }
        }
        if(flag == false)
            printf("forest");

        printf("\n");

        V.clear();
        memset(parent, 0, sizeof(parent));
    }
    return 0;
}
