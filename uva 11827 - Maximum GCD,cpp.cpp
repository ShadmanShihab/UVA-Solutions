//uva 11827 - Maximum GCD
#include <bits/stdc++.h>
using namespace std;

#define pfi(n) printf("%d\n", n)
#define sci(n) scanf("%d", &n)

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int T, ara[105], max_gcd;
    sci(T);
    getchar();
    string str;

    while(T--)
    {
        int k=0;
        getline(cin, str);

        stringstream ss(str);

        while(ss >> ara[k])
            k++;

        max_gcd = 0;
        for(int i=0; i<k; i++)
        {
            for(int j=i+1; j<k; j++)
            {
                int temp = gcd(ara[i], ara[j]);
                max_gcd = max(max_gcd, temp);
            }
        }

        pfi(max_gcd);
    }
    return 0;
}
