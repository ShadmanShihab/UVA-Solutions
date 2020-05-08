//uva 10325 Lottery(Principle of inclusion and exclusion)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

int main()
{
    //freopen("in.txt", "r", stdin);
    fastIO;
    ll n, m;
    while(cin>>n>>m)
    {
        ll ara[m + 2];
        for(int i=0; i<m; i++)
            cin>>ara[i];

        ll subsets = (1<<m) - 1;
        ll ans = 0, denom;

        for(ll i=1; i<=subsets; i++)
        {
            denom = (ll)1;
            ll setBits = __builtin_popcount(i);

            for(ll j=0; (1<<j) <= i; j++)
            {
                if(i & (1<<j))
                {
                    denom = lcm(denom, ara[j]);

                    if(denom > n){
                        denom = 1;
                        break;
                    }
                }
            }
            if(denom == 1) continue;

            if(setBits & 1)
                ans += (n / denom);
            else
                ans -= (n / denom);
        }
        cout<<n - ans<<endl;
    }
    return 0;
}
