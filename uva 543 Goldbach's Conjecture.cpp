///uva 543 Goldbach's Conjecture
#include <bits/stdc++.h>
using namespace std;

#define size 1000000
bool prime[size];
int ara[size];

void sieve()
{
    int i, j, root;
    root = sqrt(size);

    for(i=2; i<size; i++)
        prime[i] = true;

    for(i=2; i<=root; i++){

        if(prime[i] == true){

            for(j=2; i*j<=size; j++){

                prime[ i*j ] = false;

            }
        }
    }
}

int isPrime(int n)
{
    if(n<=2)
        return 0;
    return prime[n];
}

int findPrimes(int n)
{
    for(int i=3; i<n/2+1; i++){
        if(isPrime(i) && isPrime(n-i)){
            cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
        return 1;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    sieve();

    while(1)
    {
        cin>>n;

        if(n == 0)
            break;

        findPrimes(n);
    }
    return 0;
}
