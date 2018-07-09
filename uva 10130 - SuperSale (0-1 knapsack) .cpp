///uva 10130 - SuperSale
///recursive 0-1 knapsack
///O(n*capacity)

#include <bits/stdc++.h>
using namespace std;

#define Max 1010
#define MW 35
#define MP 110

int dp[Max+1][MW+1];
int cost[Max], weight[Max];
int n, capacity;

int knapsack(int i, int w)
{
    if(i > n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];

    int profit1, profit2;

    if(w + weight[i] <= capacity)
        profit1 = cost[i] + knapsack(i+1, w+weight[i]);
    else
        profit1 = 0;

    profit2 = knapsack(i+1, w);

    dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
            scanf("%d %d", &cost[i], &weight[i]);

        int g, sum = 0;
        scanf("%d", &g);

        for(int i=1; i<=g; i++)
        {
            for(int i=0; i<=Max; i++)
                for(int j=0; j<=MW; j++)
                    dp[i][j] = -1;

            int cap;
            scanf("%d", &cap);
            capacity = cap;
            sum += knapsack(1, 0);
        }
        printf("%d\n", sum);
    }
    return 0;
}
