/// uva 11015 05-2 Rendezvous
#include <bits/stdc++.h>
using namespace std;
int inf = 10000000;
int n;
int adj[30][30];
vector<string> V;

void floydWarshall()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(i==j)
                    adj[i][j] = 0;
                else if(adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int m;
    int kase = 0;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)
            break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                    adj[i][j] = inf;
            }
        }

        for(int i=0; i<n; i++){
            string str;
            cin>>str;
            V.push_back(str);
        }
        for(int i=0; i<m; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            adj[x][y] = z;
            adj[y][x] = z;
        }
        floydWarshall();

        /*for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }*/

        int min = (n*inf)+1, index = 0;

        for(int i=1; i<=n; i++){
            int sum = 0;
            for(int j=1; j<=n; j++){
                sum += adj[i][j];

            }
            //cout<<i<<" -> "<<sum<<endl;
            if(min>sum){
                min = sum;
                index = i;
            }
        }
        kase++;
        cout<<"Case #"<<kase<<" : "<<V[index-1]<<endl;
        V.clear();
    }
    return 0;
}
