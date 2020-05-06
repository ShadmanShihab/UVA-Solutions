//uva 10168	Summation of Four Primes
#include <bits/stdc++.h>
using namespace std;
int mark[10000005];
int prime[10000005], nPrime = 0;

//1 if not prime
//0 if prime

void sieve(int n)
{
    int i, j, limit = sqrt(n * 1.0) + 2;

    mark[1] = 1;

    for(int i=4; i<=n; i+=2)
        mark[i] = 1;

    prime[nPrime++] = 2;

    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nPrime++] = i;

            if(i <= limit)
            {
                for(int j=i*i; j<=n; j+=(i*2))
                    mark[j] = 1;
            }
        }
    }
}



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //fastIO;

    sieve(10000005);
    int n;

    while(cin>>n)
    {
        if(n % 2 == 0)
        {
            n-=4;
            bool flag = false;
            for(int i=0; i<nPrime; i++)
            {
                int j = n - (prime[i]);
                if(j <= 0)
                {
                    flag = false;
                    break;
                }
                if(mark[j] == 0)
                {
                    cout<<2<<" "<<2<<" ";
                    cout<<prime[i]<<" "<<j<<endl;
                    flag = true;
                    break;
                }
            }

            if(!flag)
            {
                cout<<"Impossible.\n";
            }
        }
        else
        {
            n-=5;
            bool flag = false;
            for(int i=0; i<nPrime; i++)
            {
                int j = n - (prime[i]);
                if(j <= 0)
                {
                    flag = false;
                    break;
                }
                if(mark[j] == 0)
                {
                    cout<<2<<" "<<3<<" ";
                    cout<<prime[i]<<" "<<j<<endl;
                    flag = true;
                    break;
                }
            }

            if(!flag)
            {
                cout<<"Impossible.\n";
            }
        }
    }
    return 0;
}
