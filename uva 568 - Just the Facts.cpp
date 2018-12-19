//uva 568 - Just the Facts
//dp
#include <bits/stdc++.h>
using namespace std;

int n, dp[10010];

void factorial(int n)
{
    int sum = 1, temp;
    for(int i=1; i<=n; i++)
    {
        sum = sum * i;
        while(sum % 10 == 0)
            sum /= 10;
        sum = sum % 100000;
        dp[i] = sum % 10;
    }
}

int main() {

    factorial(10000);
    while(scanf("%d", &n) == 1)
    {
        printf("%5d -> %d\n", n, dp[n]);
    }
    return 0;
}

