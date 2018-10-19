//uva 11369 - Shopaholic
//greedy tecnique
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, n;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%d", &n);
        int ara[20010];

        for(int i=1; i<=n; i++)
            scanf("%d", &ara[i]);

        sort(ara, ara+(n+1));

        //for(int i=1; i<=n; i++)
            //cout<<ara[i]<<endl;

        int sum = 0, c=0;
        for(int i=n; i>=1; i--)
        {
            c++;
            if(c == 3)
            {
                sum += ara[i];
                c = 0;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
