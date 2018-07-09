///uva 11764 - Jumping mario
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, n;

    scanf("%d", &T);
    for(int k=1; k<=T; k++)
    {
        int ara[100];
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%d", &ara[i]);

        int low = 0, high = 0;

        for(int i=1; i<n; i++){
            if(ara[i] > ara[i-1])
                high++;
            else if(ara[i] < ara[i-1])
                low++;
        }
        printf("Case %d: %d %d\n", k, high, low);
    }
    return 0;
}
