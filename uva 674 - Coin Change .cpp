///uva 674 - Coin Change
#include <bits/stdc++.h>
using namespace std;

#define Max 7495

int coin[5] = {50,25,10, 5, 1};
int make, n;
int dp[6][Max];

int coin_change(int i, int amount)
{
    if(i >= n){
        if(amount == 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][amount] != -1)
        return dp[i][amount];

    int ret1 = 0, ret2 = 0;

    if(amount - coin[i] >= 0)
        ret1 = coin_change(i, amount-coin[i]);

    ret2 = coin_change(i+1, amount);

    return dp[i][amount] = ret1 + ret2;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    n = 5;
    memset(dp, -1, sizeof(dp));

    while(scanf("%d", &make) == 1)
    {
        printf("%d\n", coin_change(0, make));
    }

    return 0;
}
