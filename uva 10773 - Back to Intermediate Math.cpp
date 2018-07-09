///uva 10773 - Back to Intermediate Math
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, u, v, d;
    scanf("%d", &T);

    for(int i=1; i<=T; i++)
    {
        scanf("%d %d %d", &d, &v, &u);

        if(u <= v){
            printf("Case %d: can't determine\n", i);
            continue;
        }
        double t1, t2;

        t1 = (d*1.0) / u ;

        t2 = (d * 1.0) / sqrt(u*u - v*v);

        if(t2 > t1)
            printf("Case %d: %0.3lf\n", i, t2-t1);
        else
            printf("Case %d: can't determine\n", i);

    }
    return 0;
}
