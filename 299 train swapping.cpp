#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, i;
    int ara[10000];
    scanf("%d", &T);

    while(T--)
    {
        int n, temp, ptr;
        int count = 0;

        scanf("%d", &n);
        for(i=1; i<=n; i++)
            scanf("%d", &ara[i]);

        ara[0] = -1;

        for(int k=2; k<=n; k++)
        {
            temp = ara[k];
            ptr = k-1;

            while(temp < ara[ptr])
            {
                count++;
                ara[ptr+1] = ara[ptr];
                ptr--;
            }
            ara[ptr+1] = temp;
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}
