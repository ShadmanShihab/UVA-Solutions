#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
     int ara[10000];
     int i, j, k, l, days, n, t, total_party, count, fri, sat;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d", &days);
         for(i=1; i<=days; i++)
            ara[i] = 0;
         scanf("%d",&total_party);
         for(i=1; i<=total_party; i++)
         {
             scanf("%d", &n);
            count = 0;

            for(j=1; j<=days; j++){
                    count++;
                if(count == n){
                    ara[j] = 1;
                    count = 0;
                }
            }
         }

        fri=0, sat=0;
        for(i=1; i<=days; i++)
        {
            fri++;
            if(fri == 6){
                ara[i] = 0;
                fri = -1;
            }
            sat++;
            if(sat == 7){
                ara[i] = 0;
                sat = 0;
            }
        }

        count = 0;
        for(i=1; i <= days; i++)
         {
             if(ara[i] == 1)
                count++;
         }
         printf("%d\n", count);
     }
     return 0;
}

