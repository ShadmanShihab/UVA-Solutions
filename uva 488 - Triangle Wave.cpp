//uva 488 - Triangle Wave
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int freq, amp;
        scanf("%d %d", &amp, &freq);

        for(int f=1 ;f<=freq; f++)
        {
            for(int i=1; i<amp; i++)
            {
                for(int j=1; j<=i; j++)
                    printf("%d", i);
                printf("\n");
            }
            for(int i=amp; i>=1; i--)
            {
                for(int j=1; j<=i; j++)
                    printf("%d", i);
                printf("\n");
            }
            if(t==T && f==freq)
                break;
            printf("\n");
        }
    }
    return 0;
}
