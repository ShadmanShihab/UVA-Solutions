#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    double n, p;
    while(scanf("%lf %lf", &n, &p) == 2){
        printf("%.0lf\n", pow(p, 1/n));
    }
    return 0;
}
