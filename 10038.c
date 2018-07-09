#include <stdio.h>
#include <stdlib.h>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n, i, j, count;
    int ara1[3010];
    int ara2[3010];
    while(scanf("%d", &n) != EOF)
    {
        count = 0;
        for(i=0; i<n; i++)
            scanf("%d", &ara1[i]);

        for(i=0; i<n; i++)
            ara2[i] = abs(ara1[i] - ara1[i+1]);

        for(i=0; i<n-1; i++)
        {
            if(ara2[i] >= 1 && ara2[i] <= n-1)
                count++;
        }

        for(i=0; i<n-2; i++)
        {
            for(j=i+1; j<n-1; j++)
                if(ara2[i] == ara2[j])
                    count--;
        }

        if(count == (n-1))
            printf("Jolly\n");
        else
            printf("Not jolly\n");

    }
    return 0;
}
