///10935 Throwing Cards Away I
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, u, v;
    queue<int> Q;

    while(scanf("%d", &n) && n)
    {
        for(int i=1; i<=n; i++)
            Q.push(i);

        printf("Discarded cards:");

        while(!Q.empty())
        {
            if(Q.size() > 1)
            {
                u = Q.front();
                Q.pop();

                printf(" %d", u);
            }
                v = Q.front();
                Q.pop();

            if(Q.empty()){
                printf("\nRemaining card: %d\n", v);
                break;
            }
            printf(",");
            Q.push(v);
        }
    }
    return 0;
}
