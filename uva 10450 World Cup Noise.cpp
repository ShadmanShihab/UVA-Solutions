//uva 10450 World Cup Noise
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 60

ll fib[MAX];

void fibo()
{
    fib[0] = 1;
    fib[1] = 2;

    for(int i=2; i<MAX; i++)
        fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fibo();

    ll T, n;
    scanf("%lld", &T);
    for(int i=1; i<=T; i++)
    {
        scanf("%lld", &n);

        printf("Scenario #%d:\n", i);
        printf("%lld\n\n", fib[n]);
    }
    return 0;
}
