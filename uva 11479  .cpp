//uva 11479 - Is this the easiest problem?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int k=1; k<=T; k++)
    {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a<0 || b<0 || c<0)
        {
            printf("Case %d: Invalid\n", k);
                continue;
        }

        if(a>=b && a>=c)
        {
            if(b+c <= a){
                printf("Case %d: Invalid\n", k);
                continue;
            }
        }
        else if(b>=a && b>=c)
        {
            if(a+c <= b){
                printf("Case %d: Invalid\n", k);
                continue;
            }
        }
        else if(c>=b && c>=a)
        {
            if(b+a <= c){
                printf("Case %d: Invalid\n", k);
                continue;
            }
        }

        if(a == b && b == c && c == a)
            printf("Case %d: Equilateral\n", k);
        else if(a == b || b == c || c == a)
            printf("Case %d: Isosceles\n", k);
        else
            printf("Case %d: Scalene\n", k);
    }
    return 0;
}
