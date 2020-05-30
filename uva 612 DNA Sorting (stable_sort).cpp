//uva 612 DNA Sorting (stable_sort)
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

string s;

int _merge(int i1, int j1, int i2, int j2)
{
    string temp = "";
    int i = i1;
    int j = i2;
    int k = 0;

    int mid = j1;
    int inversionCount = 0;

    while(i <= j1 && j <= j2)
    {
        if(s[i] <= s[j])
        {
            temp += s[i];
            i++;
        }
        else
        {
            temp += s[j];
            j++;

            inversionCount += (mid - i + 1);
        }
    }

    while(i <= j1)
        temp += s[i++];

    while(j <= j2)
        temp += s[j++];

    k = 0;
    for(i = i1; i<=j2; i++)
        s[i] = temp[k++];

    return inversionCount;
}

int mergesort(int i, int j)
{
    int mid;
    int inversionCount = 0;

    if(i < j)
    {
        mid = (i + j) / 2;
        inversionCount += mergesort(i, mid);
        inversionCount += mergesort(mid+1, j);
        inversionCount += _merge(i, mid, mid+1, j);
    }
    return inversionCount;
}

struct seq{
    int index;
    string str;
};

bool cmp(seq a, seq b)
{
    if(a.index < b.index)
        return true;
    else
        return false;

}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;
    int T; cin>>T;

    while(T--)
    {
        int n, m;
        cin>>n>>m;

        seq sq[m+5];

        for(int i=0; i<m; i++)
        {
            cin>>s;
            string org = s;

            int inv_cnt = mergesort(0, s.size()-1);
            sq[i].index = inv_cnt;
            sq[i].str = org;
        }

        stable_sort(sq, sq+m, cmp);
        //when two elements are equal, this sorts them in their order of input

        for(int i=0; i<m; i++)
            cout<<sq[i].str<<endl;

        if(T != 0)
            cout<<endl;
    }
    return 0;
}
