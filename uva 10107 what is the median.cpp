///uva 10107 What is the Median?
#include <iostream>
#include <cstdio>
using namespace std;

#define ull unsigned long long int
ull ara[10010];

void insertionSort(int i)
{
    for(int j=2; j<=i; j++){
        int temp = ara[j];
        int ptr = j-1;
        while(ptr>0 && temp<ara[ptr]){
            ara[ptr+1] = ara[ptr];
            ptr--;
        }
        ara[ptr+1] = temp;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ull n, i=1, median;

    while(scanf("%lld", &n) == 1)
    {
        ara[i] = n;
        insertionSort(i);

        if(i % 2 == 1)
        {
            median = (1 + i) / 2;
            printf("%lld\n", ara[median]);
        }
        else
        {
            int a = i / 2;
            int b = (i / 2) + 1;

            median = (ara[a] + ara[b]) / 2;
            printf("%lld\n", median);
        }
        i++;
    }
    return 0;
}
