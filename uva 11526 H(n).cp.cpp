///uva 11526 H(n)
///n/j - n/j+1
#include <bits/stdc++.h>
using namespace std;
long long H(long long n)
{
    if(n <= 0)
        return 0;

    long long res = 0;
    long long root = sqrt(n);
    long long sum = 0, countLoop = 0;
    for( int i = 1; i <= root; i=i+1 )
    {
        int res = (n / i) - (n / (i+1));
        sum += (i * res);
        countLoop += res;
    }
    //cout<<sum<<endl;
    long long remaining = n - countLoop;
    for(int i=1; i<=remaining; i++)
        sum += (n / i);

    return sum;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long n;
        cin>>n;
        cout<<H(n)<<endl;
    }
    return 0;
}
