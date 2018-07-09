#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int match_string(char ch)
{
    if(ch == 'r')
        return 0;
    else if(ch == 'p')
        return 1;
    else
        return 2;
}
int main()
{
    int win[101];
    int lost[101];

    int grid[3][3];
    char s1[12], s2[12];
    int i, j, n, k, temp, a, b, x, y, count=0;
    double w, l, ans;

    grid[0][0] = 5;
    grid[0][1] = 0;
    grid[0][2] = 1;

    grid[1][0] = 1;
    grid[1][1] = 5;
    grid[1][2] = 0;

    grid[2][0] = 0;
    grid[2][1] = 1;
    grid[2][2] = 5;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(i=0; i<=n; i++){
        win[i] = 0;
        lost[i] = 0;
        }

        scanf("%d", &k);
        temp = (k*n*(n-1)) / 2;

        if(count >= 1)
            printf("\n");
        count = 0;


        for(i=1; i<=temp; i++){
            scanf("%d", &a);
            scanf("%s", s1);
            x = match_string(s1[0]);

            scanf("%d", &b);
            scanf("%s", s2);
            y = match_string(s2[0]);

            if(grid[x][y] == 0){
                lost[a]++;
                win[b]++;
            }
            else if(grid[x][y] == 1){
                win[a]++;
                lost[b]++;
            }
        }


        for(i=1; i<=n; i++){
            if(win[i] + lost[i] == 0)
                printf("-\n");
            else if((win[i] + lost[i]) != 0){
                 ans = ((double)win[i]) / (((double)win[i]) + ((double)lost[i]));
                printf("%.3lf\n",ans);
             }
            win[i] = 0;
            lost[i] = 0;
        }
        count++;
    }
    return 0;
}
