//uva 12356 - Army Buddies
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int left[100001], right[100001];
    int s, b, L, R;

    while(1)
    {
        scanf("%d %d", &s, &b);

        if(s==0 && b==0)
            break;

        for(int i=1; i<=s+1; i++)
        {
            left[i] = i - 1;
            right[i] = i + 1;
        }

        for(int i=0; i<b; i++)
        {
            scanf("%d %d", &L, &R);

            if(left[L] < 1)
                printf("* ");
            else
                printf("%d ", left[L]);

            if(right[R] > s)
                printf("*\n");
            else
                printf("%d\n", right[R]);

            left[right[R]] = left[L];
            right[left[L]] = right[R];
        }
        printf("-\n");
    }
    return 0;
}
