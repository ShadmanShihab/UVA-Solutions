///uva 10110 light more light
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    unsigned long long int n,  root;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0)
            break;

        root = sqrt(n);

        if((root*root) == n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
