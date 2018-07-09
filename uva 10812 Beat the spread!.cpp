///uva 10812 Beat the spread!
Beat the Spread!
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a, b, x, y;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &a, &b);

        x = (a + b) / 2;
        y = a - x;
        if(x < 0 || y < 0)
            printf("impossible\n");
        else if((x+y == a) && (abs(x-y)==b))
            printf("%d %d\n", x, y);
        else
            printf("impossible\n");
    }
    return 0;
}
