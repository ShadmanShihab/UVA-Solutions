//uva 11389 - The Bus Driver Problem
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, d, r;

    while(1)
    {
        scanf("%d %d %d", &n, &d, &r);
        if(n==0 && d==0 && r==0)
            break;

        int first[101], second[101];

        for(int i=0; i<n; i++)
            scanf("%d", &first[i]);
        for(int i=0; i<n; i++)
            scanf("%d", &second[i]);

        sort(first, first+n);
        sort(second, second+n);

        int sum = 0;

        for(int i=0; i<n; i++)
        {
            if(first[i] + second[(n-1) - i] > d)
            {
                sum += ((first[i] + second[(n-1) - i]) - d) * r;
            }
        }
        cout<<sum<<endl;
    }
}
