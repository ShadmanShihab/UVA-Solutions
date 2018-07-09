///uva 524 Prime Ring Problem
///recursive backtracking
#include <bits/stdc++.h>
using namespace std;

int prime[101];
int number[101];
int visited[101];

void sieve()
{
    for(int i=2; i<=101; i++)
        prime[i]=1;
    for(int i=2; i<=101; i++){
            for(int j=2; i*j<=101; j++)
                prime[i*j] = 0;
    }
}
void bktk(int at, int n)
{
    if(at == n+1)
    {
        if( prime[number[1] + number[at-1] ] == 1){     ///to check last and first element
        for(int i=1; i<=n; i++){
                printf("%d", number[i]);    ///printing the elements
                if(i != n)
                    printf(" ");
            }
        printf("\n");
        }
        return;
    }
    for(int i=2; i<=n; i++)
    {
        if(visited[i]==0 && prime[i + number[at-1]]==1)     ///to check prime
        {
        visited[i] = 1;
        number[at] = i;
        bktk(at+1, n);
        visited[i] = 0;    ///this should be made 0 after recursive call
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, kase=0, c=0;
    sieve();

    while(scanf("%d", &n)==1)
    {
        if(c==1)
            printf("\n");

        kase++;
        memset(visited, 0, sizeof(visited));
        number[1] = 1;

        printf("Case %d:\n", kase);
        bktk(2, n);
        c = 1;
    }
    return 0;
}
