#include <bits/stdc++.h>
using namespace std;

#define type unsigned long long
///we can also take m globally
///then we wont need to pass m as parameter
type mod(type x, type n, type m)
{
    type y;
    if(n==0)
        return 1;

    else if(n % 2 == 0)
    {
        y = mod(x, n/2, m);
        return (y*y) % m;
    }

    else
        return ( (x % m) * mod(x, n-1, m) ) % m;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    type b, p, m;

    while(scanf("%lld %lld %lld", &b, &p, &m) == 3)
    {
        cout<<mod(b, p, m)<<endl;
    }
    return 0;
}
