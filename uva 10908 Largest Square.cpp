//uva 10908 Largest Square
#include <bits/stdc++.h>
using namespace std;

char grid[101][101];
int T, m, n, i, j, q, r, c, dr1, dr2, dc1, dc2;
char ch;

bool checkSquare()
{
    if ( dr1 < 0 || dr2 == m || dc1 < 0 || dc2 == n )
        return false;

    // up
    for ( int i = dc1; i <= dc2; i++ )
        if ( grid[dr1] [i] != ch ) return false;

    // right
    for ( int i = dr1; i <= dr2; i++ )
        if ( grid[i] [dc2] != ch ) return false;

    // down
    for ( int i = dc1; i <= dc2; i++ )
        if ( grid[dr2] [i] != ch ) return false;

    // left
    for ( int i = dr1; i <= dr2; i++ )
        if ( grid [i] [dc1] != ch ) return false;

    return true;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    scanf("%d", &T);
    while(T--)
    {
        scanf ("%d %d %d", &m, &n, &q);
        printf ("%d %d %d\n", m, n, q);

        for ( int i = 0; i < m; i++ )
            scanf ("%s", grid[i]);

        for ( int i = 0; i < q; i++ ) {
            scanf ("%d %d", &r, &c);

            int length = 0;
            ch = grid [r] [c];
            dr1 = r;
            dr2 = r;
            dc1 = c;
            dc2 = c;

            while ( checkSquare()) {
                length++;

                dr1--;
                dc1--;

                dr2++;
                dc2++;
            }

            printf ("%d\n", length * 2 - 1);
        }
    }
}
