//uva 10843	Anne's game - (BigMod)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 10000
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define pb push_back

long long limit = 4294967296;
int MOD = 1000000007;
template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... anst)
{
    print(first);
    print(anst ...) ;
}

/*direction array*/

/***4 moves***/
/*
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
*/
/***8 moves***/
/*
int dx[] = { 0,  0, -1, -1, -1, +1, +1, +1 } ;
int dy[] = {-1, +1, -1,  0, +1, -1,  0, +1 } ;
*/

/*direction array ends*/

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b)
{
    return (a * (b / gcd(a, b)));
}

ll bigMod(ll a, ll n, ll m)
{
    if(n == 0)
        return 1;

    ll x = bigMod(a, n/2, m);
    x = (x * x) %  m;

    if(n % 2 == 1)
        x = (x * a) % m;

    return x;
}

int main()
{
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);

    fastIO;
    int T; cin>>T;

    for(int t=1; t<=T; t++)
    {
        ll n; cin>>n;

        ///The number of labeled trees on N vertices is N^N-2
        ll res = bigMod(n, n-2, 2000000011);
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}
