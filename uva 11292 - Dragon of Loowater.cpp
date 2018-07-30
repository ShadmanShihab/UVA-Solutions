//uva 11292 - Dragon of Loowater
#include <bits/stdc++.h>
using namespace std;

#define Max 50000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, m;
    int knights[Max], dragons[Max];

    while(scanf("%d %d", &n, &m))
    {
        if(n==0 && m==0)
            break;

        for(int i=0; i<n; i++)
            scanf("%d", &dragons[i]);

        for(int i=0; i<m; i++)
            scanf("%d", &knights[i]);

        sort(dragons, dragons+n);
        sort(knights, knights+m);

        bool flag = false;
        int k = 0, sum = 0;

        for(int i=0; i<n; i++)
        {
            while(k < m && dragons[i] > knights[k])
                k++;

            if(k >= m) {
                flag = true;
                break;
            }

            sum += knights[k];
            k++;
        }
        if(flag)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", sum);
    }
    return 0;
}
