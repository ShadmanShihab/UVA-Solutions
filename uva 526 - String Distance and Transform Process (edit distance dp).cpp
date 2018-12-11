//uva 526 - String Distance and Transform Process
//edit distance dp
#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int editDistance(char s1[], char s2[], int m, int n)
{
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1;
        }
    }
    return dp[m][n];
}

void trace_result(char x[], char y[], int m, int n)
{
    int i, j, kase=1;
    i = m;
    j = n;

    while(i || j)
    {
        if(i>0 && x[i-1]==y[j-1])
        {
            i--; j--;
            continue;
        }
        else if(i>0 && dp[i-1][j]+1 == dp[i][j])
        {
            printf("%d Delete %d\n", kase++, i);
            i--;
        }
        else if(i>0 && j>0 && (dp[i][j] == dp[i-1][j-1] + 1))
        {
            printf("%d Replace %d,%c\n", kase++, i, y[j-1]);
            i--;
            j--;
        }
        else if(j>0)
        {
            printf("%d Insert %d,%c\n", kase++, i+1, y[j-1]);
            j--;
        }
    }
}

int main()
{
    char str1[101], str2[101];
    while(gets(str1))
    {
        gets(str2);

        int m = strlen(str1);
        int n = strlen(str2);

        cout<<editDistance(str1, str2, m, n)<<endl;

        trace_result(str1, str2, m, n);
    }
    return 0;
}
