///uva 10487 - Closest Sums

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define max 1010

#define lld long long int
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    lld number[1010];
    int count=0, n;

    while(1)
    {
        scanf("%d", &n);

        if(n==0)
            break;

        count++;
        printf("Case %d:\n", count);

        for(int i=0; i<n; i++)
            scanf("%lld", &number[i]);

        int m;
        scanf("%d", &m);
        while(m--)
        {
            lld query;
            lld sum, diff;
            scanf("%lld", &query);


            sum = number[0] + number[1];

            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    diff = number[i] + number[j];

                    if(abs(sum - query) > abs(query - diff))
                        sum = diff;
                }
            }
            printf("Closest sum to %lld is %lld.\n", query, sum);
        }
    }
    return 0;
}
