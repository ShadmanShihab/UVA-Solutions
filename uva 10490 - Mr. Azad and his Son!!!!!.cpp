//uva 10490 - Mr. Azad and his Son!!!!!
#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long long
int mark[100] = {0};
//1 if not prime
//0 if prime

void sieve(ul n)
{
    ul i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 1;

    for(ul i=4; i<=n; i+=2)
        mark[i] = 1;


    for(ul i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {

            if(i <= limit)
            {
                for(ul j=i*i; j<=n; j+=(i*2))
                    mark[j] = 1;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sieve(33);

    ul n;
    while(1)
    {
        scanf("%llu", &n);
        if(n == 0)
            break;

        if(!mark[n])
        {
            if(n==11 || n==23 || n==29)
                printf("Given number is prime. But, NO perfect number is available.\n");
            else{
                ul res = pow(2, n-1) * (pow(2,n)-1);
                cout<<"Perfect: "<<res<<"!"<<endl;
            }
        }
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
