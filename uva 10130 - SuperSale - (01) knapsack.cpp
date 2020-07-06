//uva 10130 - SuperSale - (0/1) knapsack
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 1000
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PI acos(-1)
#define all(a) a.begin(), a.end()
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

int weight[Max];
int cost[Max];
int n;
int dp[Max][Max];

int knapsack(int i, int cap)
{
    if(i == n+1)
        return 0;

    if(dp[i][cap] != -1)
        return dp[i][cap];


    int profit1, profit2;

    if(cap - weight[i] >= 0)
        profit1 = cost[i] + knapsack(i+1, cap - weight[i]);
    else
        profit1 = 0;

    profit2 = knapsack(i+1, cap);

    return dp[i][cap] = max(profit1, profit2);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    fastIO;

    int t; cin>>t;

    while(t--)
    {
        memset(dp, -1, sizeof(dp));

        cin>>n;

        for(int i=1; i<=n; i++)
            cin>>cost[i]>>weight[i];

        ll sum = 0;
        int q; cin>>q;
        while(q--)
        {
            int capacity;
            cin>>capacity;
            sum += knapsack(0, capacity);
        }
        cout<<sum<<endl;
    }
    return 0;
}
