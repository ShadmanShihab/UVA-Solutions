//uva 10192 Vacation
//lcs dp(bottom up)
//O(mn)
#include <bits/stdc++.h>
using namespace std;

int lcs(char x[], char y[], int m, int n)
{
    int L[m+1][n+1];
    int i, j;

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(x[i-1] == y[j-1])
                L[i][j] = 1 + L[i-1][j-1];
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char father[1000001], mother[1000001];
    int kase = 0;
    while(gets(father))
    {
        if(father[0] == '#')
            break;

        gets(mother);
        int m = strlen(father);
        int n = strlen(mother);

        printf("Case #%d: you can visit at most %d cities.\n", ++kase, lcs(father, mother, m, n));
    }
    return 0;
}
