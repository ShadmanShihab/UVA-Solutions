#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, res, c;
    while(scanf("%d %d", &n, &k) == 2)
    {
        c = 0;
        res = 0;
        while(n>0)
        {
            c += n;
            res += n;
            n = res / k;
            res  = res % k;
        }
        cout<<c<<endl;
    }
    return 0;
}
