//uva 11152 - Colourful Flowers
#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int main()
{
    double a, b, c, p, s;
    double triangleArea, circumRadius, inRadius;
    double circleArea, inCircleArea;
    double sunflower, violets, roses;

    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        p = a + b + c;
        s = p / 2;

        triangleArea = sqrt(s * (s-a) * (s-b) * (s-c));
        circumRadius = (a * b * c) / (4 * triangleArea);
        circleArea = PI * circumRadius * circumRadius;
        sunflower = circleArea - triangleArea;

        inRadius = triangleArea / s;
        inCircleArea = PI * inRadius * inRadius;
        roses = inCircleArea;

        violets = triangleArea - roses;

        printf("%0.4lf %0.4lf %0.4lf\n", sunflower, violets, roses);
    }
    return 0;
}
