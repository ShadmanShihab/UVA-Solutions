///uva 10394 - Twin Primes
#include <bits/stdc++.h>
using namespace std;

#define max  20000010
#define lld long long int

bool prime[max];
int twin_prime[max];

void sieve()
{
    memset(prime, true, sizeof(prime));

    prime[1] = false;

    int root = sqrt(max);

    for(int i=2; i<=root; i++){
        if(prime[i]){
            for(int j=2; i*j <= max; j++){
                prime[i*j] = false;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sieve();

    int j=1;
    for(int i=3; i<=max; i++){
        if(prime[i] && prime[i+2]){
            twin_prime[j++] = i;
        }
    }

    int n;
    while(scanf("%d", &n)==1)
    {
        printf("(%d, %d)\n",twin_prime[n],twin_prime[n]+2);
    }
    return 0;
}
