///uva 11044 - Searching for Nessy
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int res = (n / 3) * (m / 3);
        printf("%d\n", res);
    }
    return 0;
}
