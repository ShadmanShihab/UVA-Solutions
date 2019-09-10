#include <bits/stdc++.h>
using namespace std;

#define Max 100010

int parent[Max];
int res;

void makeSet(int n)
{
    for(int i=1; i<=n; i++) parent[i] = i;
}

int Find(int r)
{
    if(r == parent[r])
        return r;

    return parent[r] = Find(parent[r]);
}

void Union(int a, int b)
{
    int u = Find(a);
    int v = Find(b);

    if(u != v){
        parent[u] = v;
        res--;
    }
}



int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    //fastIO;

    int t;
    char s[10];
    scanf("%d ", &t);

    int n;
    bool flag = false;

    while(t--)
    {
        if(flag)
            printf("\n");
        flag = true;
        gets(s);

        n = s[0]-64;
        makeSet(n);
        res = n;

        while(gets(s))
        {
            if(s[0] == '\0')
                break;
            int a = s[0] - 64;
            int b = s[1] - 64;

            Union(a, b);
        }
        cout<<res<<endl;

    }
    return 0;
}
