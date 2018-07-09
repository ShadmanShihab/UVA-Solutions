///uva 10469 - To Carry or not to Carry
///xor implementation
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ull n1, n2;
    while(cin>>n1>>n2)
    {
        ull n3;
        n3 = n1 ^ n2;
        printf("%lld\n", n3);
    }
    return 0;
}
