///uva 10653 Bombs no the are mines
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
bool visited[1002][1002];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int level[1002][1002];
int grid[1002][1002];
int r, c;

void bfs(int sx, int sy)
{
    visited[sx][sy] = true;
    queue<pii> Q;               ///queue using pair <int, int>
    Q.push( pii(sx, sy) );

    while(!Q.empty())
    {
        pii top;
        top = Q.front();
        Q.pop();

        for(int k=0; k<4; k++)  //direction array
        {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];

            if( (tx>=0 && tx<r && ty>=0 && ty<c) && (visited[tx][ty]!=true) && (grid[tx][ty]!=-1) ){
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

    int n, x, y, z, start1, start2;

    while(scanf("%d %d", &r, &c), (r || c) )
    {
        memset(grid, 0, sizeof(grid));
        memset(visited, false, sizeof(visited));
        memset(level, 0, sizeof(level));

        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d %d", &x, &y);

            for(int j=0; j<y; j++){
                scanf("%d", &z);

                grid[x][z] = -1;
            }
        }
        scanf("%d %d", &start1, &start2);   ///starting nodes
        bfs(start1, start2);

        int des1, des2;
        scanf("%d %d", &des1, &des2);       ///destination nodes
        printf("%d\n", level[des1][des2]);
    }
    return 0;
}
