//uva 10499 - The Land of Justice
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    while(scanf("%lld", &n) == 1)
    {
        if(n < 0)
            break;
        if(n == 1)
            printf("0%%\n");
        else
            printf("%lld%%\n", n*100/4);
    }
    return 0;
}
