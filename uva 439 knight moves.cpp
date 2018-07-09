///uva 439 knight moves
#include <bits/stdc++.h>
using namespace std;

int grid[10][10];
char str1[5], str2[5];
bool visited[10][10];
int level[10][10];
int fx[]={1, -1, 1, -1, 2, 2, -2, -2};
int fy[]={2, 2, -2, -2, 1, -1, 1, -1};
#define pii pair<int, int>

int retChar(char ch)
{
    return (ch - 97);
}
int retInt(char ch)
{
    return (ch - 49);
}


void bfs(int sx, int sy)
{
    visited[sx][sy] = true;
    queue<pii> Q;
    Q.push( pii(sx, sy) );

    while(!Q.empty())
    {
        pii top;
        top = Q.front();
        Q.pop();

        for(int k=0; k<8; k++)  //direction array
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if( (tx>=0 && tx<8 && ty>=0 && ty<8) && (visited[tx][ty]!=true) ){
                visited[tx][ty] = true;
                level[tx][ty] = level[top.first][top.second] + 1;
                Q.push( pii(tx,ty) );
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int s1, s2, d1, d2;
    while(scanf("%s %s", &str1, &str2) == 2)
    {
        memset(visited, false, sizeof(visited));
        memset(level, 0, sizeof(level));
        memset(grid, 0, sizeof(grid));

        s2 = retChar(str1[0]);
        s1 = retInt(str1[1]);

        d2 = retChar(str2[0]);
        d1 = retInt(str2[1]);

        bfs(s1, s2);

        printf("To get from %s to %s takes %d knight moves.\n",str1, str2, level[d1][d2]);

    }
    return 0;
}
