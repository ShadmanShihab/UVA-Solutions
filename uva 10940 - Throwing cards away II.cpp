///uva 10940 - Throwing cards away II
#include <iostream>
#include <cstdio>
using namespace std;

#define max 500000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int result[max+5];

    result[1] = 1;
    result[2] = 2;

    int temp = 2;
    /*int count = 2;
    int k = 2;
    while(k<max)
    {
        for(int i=1; i<=count; i++){
            result[k] = temp;
            k++;
            temp += 2;
        }
        count = count * 2;
        temp = 2;
    }*/
    for(int i=3; i<=max; i++){
        if(i < temp)
            temp = 2;
        result[i] = temp;
        temp += 2;
    }
    int n;
    while(scanf("%d", &n) && n)
    {
        printf("%d\n", result[n]);
    }
    return 0;
}
