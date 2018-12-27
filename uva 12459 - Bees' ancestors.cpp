//uva 12459 - Bees' ancestors
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll ara[101];
    int n;

    ara[0] = ara[1] = 1;
    for(int i=2; i<101; i++)
        ara[i] = ara[i-1] + ara[i-2];

    while(scanf("%d", &n) && n!=0)
        printf("%lld\n", ara[n]);

    return 0;
}
