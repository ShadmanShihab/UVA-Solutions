#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, count, n, a, d=0, z;
    int p_created[15];
    int p_required[15];

    while(1)
    {
        d++;
        count = 0;
        scanf("%d", &n);
        if(n < 0)
            break;
        for(i=0; i<12; i++)
            scanf("%d", &p_created[i]);
        for(i=0; i<12; i++)
            scanf("%d", &p_required[i]);

        printf("Case %d:\n", d);

        if(n >= p_required[0]){
            printf("No problem! :D\n");
            count = n - p_required[0];
        }
        else{
            printf("No problem. :(\n");
            count = n;
        }

        for(i=0; i<11; i++){
            if((count+p_created[i]) >= p_required[i+1]){
                printf("No problem! :D\n");
                count = (count+p_created[i]) - p_required[i+1];
            }
            else{
                printf("No problem. :(\n");
                count += p_created[i];
            }
        }
    }
    return 0;
}
