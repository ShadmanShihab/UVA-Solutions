/// uva 821 Page Hopping
/// floyd warshall
#include <bits/stdc++.h>
using namespace std;

int adj[110][110];
int inf = 1000;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a, b;
    int kase = 0;
    while(1)
    {
        int n=0;
        for(int i=0; i<=101; i++)
            for(int j=0; j<=101; j++)
                adj[i][j] = inf;

        scanf("%d %d", &a, &b);

        if(a==0 && b==0)
            break;
        adj[a][b] = 1;

        if(a>b)
            n = a;
        else
            n = b;

        while(1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if(x==0 && y==0)
                break;

            adj[x][y] = 1;

            if(n<x)
                n = x;
            if(n<y)
                n = y;
        }

        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(adj[i][j] > adj[i][k] + adj[k][j])
                        adj[i][j] = adj[i][k] + adj[k][j];

        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(i == j)
                    adj[i][j] = 0;

        int sum = 0, count=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj[i][j] < inf && i!=j){
                    sum += adj[i][j];
                    count++;
                }
            }
        }

        /*for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<adj[i][j]<<"  ";
            cout<<endl;
        }*/

        double res = (double)sum / (double)count;
        //cout<<sum<<" "<<a<<" "<<count<<endl;
        kase++;
        printf("Case %d: average length between pages = %0.3lf clicks\n",kase, res);
    }
    return 0;
}
