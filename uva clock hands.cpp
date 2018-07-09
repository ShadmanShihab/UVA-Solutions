#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h, m, hh, mh;
    double difference;

    while(scanf("%lf %*c %lf", &h, &m) != EOF)
    {
        if(h == 0 && m == 0)
            break;

        hh = (h*30) + (m*0.5);
        mh = (m * 6);

        difference = abs(hh - mh);

        if(difference > 180)
            difference = 360 - difference;

        printf("%0.3lf\n", difference);
    }
    return 0;
}


