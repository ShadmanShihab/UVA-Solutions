///uva 147 - Dollars
///coin change
#include<bits/stdc++.h>
using namespace std;

#define Max 30010
#define ull unsigned long long int
int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ull dp[Max];

void coin_change()
{
    dp[0] = 1;

    for(int i=0; i<11; i++)
    {
        for(int j=coin[i], k=0; j<=Max; j++, k++)
        {
            dp[j] += dp[k];
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    double n;
    memset(dp, 0, sizeof(dp));
    coin_change();

    while(1)
    {
        scanf("%lf", &n);
        if(n == 0.00)
            break;

        ull a = static_cast<ull>(n * 100 + 0.5);
        printf("%6.2lf%17llu\n", n, dp[a]);
    }
    return 0;
}
