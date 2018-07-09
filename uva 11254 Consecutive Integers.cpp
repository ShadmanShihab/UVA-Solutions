//uva 11254 Consecutive Integers
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a, n, sum;
    while(1)
    {
        scanf("%d", &sum);

        if(sum == -1)
            break;

        int root = sqrt(2 * sum);

        for(n = root; n>0; n--){
            if((2*sum + n - n*n) % (2*n) == 0){
                a = (2*sum + n - n*n) / (2*n);
                break;
            }
        }

        printf("%d = %d + ... + %d\n", sum, a, a+n-1);
    }
    return 0;
}
