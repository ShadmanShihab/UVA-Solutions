#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, j, k, key, a;
    int ara[102];

    scanf("%d", &t);
    for(k=1; k<=t; k++){

        scanf("%d", &n);

        for(i=1; i<=n; i++){
            scanf("%d", &ara[i]);
        }

        for(j=2; j<=n; j++){
            key = ara[j];
            i = j - 1;
            while(i>0 && ara[i]>key){
                ara[i+1] = ara[i];
                i--;
            }
            ara[i+1] = key;
        }

        a = (n/2)+1;
        printf("Case %d: %d\n",k, ara[a]);
    }
    return 0;
}
