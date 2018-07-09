///uva 10452 marcus
///dfs
#include <bits/stdc++.h>
using namespace std;

char path[] = "IEHOVA#";
int fx[] = {-1, 0, 0};
int fy[] = {0, 1, -1};
int len;
int n, m;
char grid[10][100];

void dfs(int i, int j, int at)
{
    for(int k=0; k<3; k++)
    {
        int x = i + fx[k];
        int y = j + fy[k];

        if(x>=0 && x<n && y>=0 && y<m)
        {
            if(grid[x][y] == path[at])
            {
                if(fx[k] == -1 && fy[k] == 0)
                    printf("forth");
                else if(fx[k] == 0 && fy[k] == 1)
                    printf("right");
                else if(fx[k] == 0 && fy[k] == -1)
                    printf("left");

                if(grid[x][y] == '#')
                    break;
                else
                    printf(" ");
                //cout<<"at = "<<path[at]<<"  x = "<<fx[k]<<"  y = "<<fy[k]<<endl;
                dfs(x, y, at+1);
                continue;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);

        for(int i=0; i<n; i++)
                scanf("%s", &grid[i]);

        /*for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                cout<<grid[i][j];
            cout<<endl;
        }*/

        for(int i=n-1; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == '@'){
                    dfs(i, j, 0);
               // cout<<i<<"  "<<j<<endl;
            }
        printf("\n");
    }
    return 0;
}
