#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 200005
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


int main()
{
    fastIO;
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);

    int n, t;
    while(cin>>n>>t)
    {
        if(n==0 && t==0) break;

        int coins[n+2];

        for(int i=0; i<n; i++) cin>>coins[i];

        while(t--)
        {
            ll need; cin>>need;
            ll LCM;
            ll f = INT_MIN, s = INT_MAX;
            bool flag = false;
            for(int a=0; a<n; a++)
            {
                if(flag) break;
                for(int b=a+1; b<n; b++)
                {
                    if(flag) break;
                    for(int c=b+1; c<n; c++)
                    {
                        if(flag) break;
                        for(int d=c+1; d<n; d++)
                        {
                            if(flag) break;

                            LCM = lcm(coins[a], lcm(coins[b], lcm(coins[c], coins[d])));

                            if(need % LCM == 0)
                            {
                                flag = true;
                                break;
                            }
                            else
                            {
                                ll d = need / LCM;
                                f = max(f, LCM*d);
                                s = min(s, (LCM*(d+1)));
                            }
                        }
                    }
                }
            }
            if(flag)
                cout<<need<<" "<<need<<endl;
            else
                cout<<f<<" "<<s<<endl;
        }
    }
    return 0;
}
