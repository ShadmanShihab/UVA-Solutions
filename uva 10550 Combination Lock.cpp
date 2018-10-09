//uva 10550 Combination Lock
#include <bits/stdc++.h>
using namespace std;

int countDegree(int a, int b)
{
    int degree;

    if(a < b)
        degree = (40 + (a - b)) * 9;
    else
        degree = (a - b) * 9;
    return degree;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int s, a, b, c;
    while(scanf("%d %d %d %d", &s, &a, &b, &c))
    {
        if(s==0 && a==0 && b==0 && c==0)
            break;

        int degree = 720;
        degree += countDegree(s, a);
        degree += 360;
        degree += countDegree(b, a);    //as it is anti-clockwise, instead of going a to b
                                        //it will go from b to a
        degree += countDegree(b, c);

        printf("%d\n", degree);
    }
    return 0;
}
