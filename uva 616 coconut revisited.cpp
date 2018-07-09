///uva 616 coconut revisited
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);

    int n, i, j, count, res;

    while(1)
    {
        bool flag = false;

        scanf("%d", &n);

        if(n<0)
            break;

        //int root = sqrt(n) + 1;

        for(i=10; i>=2; i--){
            res = n;
            count = 0;
            for(j=1; j<=i; j++){
                if(res % i == 1){
                    res = res - (res/i) - 1;
                    count++;
                }
            }
            if(count==i && res%i==0){
                printf("%d coconuts, %d people and 1 monkey\n",n,i);
                flag = true;
                break;
            }
        }
        if(flag == false)
            printf("%d coconuts, no solution\n",n);
    }
    return 0;
}
