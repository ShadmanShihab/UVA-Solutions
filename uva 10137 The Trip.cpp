//uva 10137 The Trip
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    while(1)
    {
        scanf("%d", &n);

        if(n==0) break;

        double ara[1010], avg=0;

        for(int i=0; i<n; i++){
            scanf("%lf", &ara[i]);
            avg += ara[i];
        }
        avg /= n;
        double pos = 0, neg = 0;
        for(int i=0; i<n; i++){
            double diff = (long) ((ara[i] - avg) * 100.00) / 100.0;

            if(diff > 0)
                pos += diff;
            else
                neg += diff;
        }
        neg *= -1;
        printf("$%.2lf\n", neg > pos ? neg : pos);
    }
    return 0;
}
