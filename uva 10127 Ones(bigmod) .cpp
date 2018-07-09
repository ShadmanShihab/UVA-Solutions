///uva 10127 Ones(bigmod)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll BigMod(ll n, ll p, ll m)
{
    if(p==0)
        return 1;
    if(p % 2 == 0)
    {
        ll ret = BigMod(n, p/2, m);
        return ((ret%m) * (ret%m)) %m;
    }
    else
        return ((n%m) * (BigMod(n, p-1, m) %m))%m;
}

int main()
{
    ll ones;
    ll m;

    int c;

    while(scanf("%lld",&m)==1)
    {
        c = 1;
        ones = 1;

        while(ones % m!=0)
        {
            ones = (ones*10) + 1;
            c++;
            ones = BigMod(ones,1,m);
        }
        printf("%d\n",c);
    }
      return 0;
}
