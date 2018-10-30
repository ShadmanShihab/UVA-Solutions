//uva 10924 - Prime Words
#include <bits/stdc++.h>
using namespace std;

int mark[1000002];
//1 if not prime
//0 if prime

void sieve(int n)
{
    memset(mark, 0, sizeof(mark));
    int i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 0;
    for(int i=4; i<=n; i+=2)
        mark[i] = 1;

    for(i=3; i<=n; i++)
    {
        if(!mark[i])
        {
            if(i <= limit)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j] = 1;
            }
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve(1000000);

    string str;
    while(cin>>str)
    {
        int len = str.size();
        int sum = 0;

        for(int i=0; i<len; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                sum += (str[i] - 38);
            else if(str[i] >= 'a' && str[i] <= 'z')
                sum += (str[i] - 96);
        }
        if(mark[sum])
            printf("It is not a prime word.\n");
        else
            printf("It is a prime word.\n");
    }
    return 0;
}
