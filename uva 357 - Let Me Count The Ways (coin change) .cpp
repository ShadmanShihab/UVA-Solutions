///uva 357 - Let Me Count The Ways
#include <bits/stdc++.h>
using namespace std;

#define Max 30010
#define ull unsigned long long int
ull dp[Max];
int coin[6] = {1, 5, 10, 25, 50};

void coin_change()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i=0; i<5; i++)
    {
        for(int j=coin[i], k=0; j<=Max; j++, k++)
        {
            dp[j] = dp[j] + dp[k] ;
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) == 1)
    {
        coin_change();
        ull a = dp[n];

        if(a==1)
            printf("There is only %llu way to produce %d cents change.\n", a, n);
        else
            printf("There are %llu ways to produce %d cents change.\n", a, n);
    }
    return 0;
}
