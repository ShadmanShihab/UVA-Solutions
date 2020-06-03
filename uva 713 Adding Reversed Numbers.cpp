//uva 713 Adding Reversed Numbers
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


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;
    int T; cin>>T;

    while(T--)
    {
        string s1, s2;
        cin>>s1>>s2;

        int len1 = s1.size(), len2 = s2.size();

        string t1 = "", t2 = "";

        bool z = true;
        for(int i=len1-1; i>=0; i--)
        {
            if(s1[i] == '0' && z)
            {
                continue;
            }
            else
            {
                z = false;
                t1 += s1[i];
            }
        }


        z = true;
        for(int i=len2-1; i>=0; i--)
        {
            if(s2[i] == '0' && z)
            {
                continue;
            }
            else
            {
                z = false;
                t2 += s2[i];
            }
        }
        int carry = 0, x=len1-1, y=len2-1, val;
        int v1, v2;
        string res = "";
        while(x >=0 && y >=0)
        {
            v1 = t1[x--] - '0';
            v2 = t2[y--] - '0';

            val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;

            res += val + '0';
        }

        while(x >= 0)
        {
            v1 = t1[x--] - '0';
            val = v1 + carry;
            carry = val / 10;
            val = val % 10;

            res += val + '0';
        }


        while(y >= 0)
        {
            v2 = t2[y--] - '0';
            val = v2 + carry;
            carry = val / 10;
            val = val % 10;

            res += val + '0';
        }

        if(carry > 0)
            res += (carry + '0');


        string ans = "";

        z = true;
        for(int i=0; i<res.size(); i++)
        {
            if(res[i] == '0' && z)
            {
                continue;
            }
            else
            {
                z = false;
                ans += res[i];
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
