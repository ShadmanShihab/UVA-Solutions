///uva 294 Divisors
#include <bits/stdc++.h>
using namespace std;

#define type unsigned long long

int divisor(int n)
{
    int root = sqrt(n);
    int count = 0;

    for(type i=1; i<=root; i++){
        if(n % i == 0)
            count += 2;
    }
    if(root*root==n)
        return count-1;
    else
        return count;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int l, u, n, max, d, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &l, &u);

        max = -1;

        printf("Between %d and %d, ", l, u);

        while(l<=u)
        {
            d = divisor(l);
            if(max<d){
                max = d;
                n = l;
            }
            l++;
        }
        printf("%d has a maximum of %d divisors.\n", n, max);
    }
    return 0;
}
