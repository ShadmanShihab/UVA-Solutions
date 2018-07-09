///uva 572 - Oil Deposits
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

vector<string> V;
bool visited[101][101];
int r, c;
int dx[] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

void dfs(int u, int v)
{
    if(visited[u][v] == true)
        return;

    visited[u][v] = true;

    for(int i=0; i<8; i++)
    {
        int x = u + dx[i];
        int y = v + dy[i];

        if(x>=0 && x<r && y>=0 && y<c)
        {
            if(V[x][y] == '@')
                dfs(x, y);
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string str;

    while(scanf("%d %d", &r, &c))
    {
        memset(visited, false, sizeof(visited));
        V.clear();

        if(r==0 && c==0)
            break;
        for(int i=0; i<r; i++)
        {
            cin>>str;
            V.push_back(str);
        }

        int count = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!visited[i][j]){

                    if(V[i][j] == '@'){
                        count++;
                        dfs(i, j);
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
