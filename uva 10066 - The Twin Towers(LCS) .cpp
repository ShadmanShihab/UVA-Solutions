//10066 - The Twin Towers
//lcs
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pfi(n) printf("%d\n", n)
#define sci(n) scanf("%d", &n)

#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=1; i<=n; i++)
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

int LCS(int x[], int y[], int m, int n)
{
    int L[m+1][n+1];

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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);

    int n, m, t=0;
    bool flag = false;
    while(scanf("%d %d", &m, &n))
    {
        if(flag)
            printf("\n");
        flag = false;
        if(m == 0 && n==0) break;

        t++;
        int a[m], b[n];

        for(int i=0; i<m; i++)
            sci(a[i]);
        for(int i=0; i<n; i++)
            sci(b[i]);

        printf("Twin Towers #%d\n", t);
        printf("Number of Tiles : %d\n", LCS(a, b, m, n));
        flag = true;
    }
    return 0;
}
