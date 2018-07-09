///uva 10189 Minesweeper
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char grid[101][101];
    int row[] = {0,1,1,1,0,-1,-1,-1};
    int col[] = {-1,-1,0,1,1,1,0,-1};
    int r, c, field = 1, count;


    while(scanf("%d %d", &r, &c), r, c){
        for(int i=0; i<r; i++)
            scanf("%s", grid[i]);

        if(field>1)
            printf("\n");

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                count = 0;
                if(grid[i][j] == '*')
                    continue;

                for(int k=0; k<8; k++){
                    if(i+row[k]<0 || i+row[k]>=r || j+col[k]<0 || j+col[k]>=c)
                        continue;
                    if( grid[i + row[k]][j + col[k]] == '*')
                        count++;
                }
                grid[i][j] = count + '0';
            }
        }
        printf("Field #%d:\n", field++);

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
