//uva 10394	Twin Primes
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair

long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

int mark[20000005];
int prime[20000005], nPrime = 0;
vector <pii> twinpair;
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

void calcTwinPair()
{
    for(int i=0; i<nPrime-1; i++)
    {
        if(prime[i] + 2 == prime[i+1])
        {
            twinpair.push_back(mp(prime[i], prime[i+1]));
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    fastIO;
    sieve(20000002);

    calcTwinPair();

    int n;
    while(cin>>n)
    {
        cout<<"("<<twinpair[n-1].first<<", "<<twinpair[n-1].second<<")"<<endl;
    }
    return 0;
}
