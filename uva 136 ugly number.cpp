///uva 136 ugly number
#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long

int main()
{
    ll ara[1505] = {0};
    ll a=1, b=1, c=1, x=2, y=3, z=5;
    int k = 2;
    ara[1] = 1;

    while(ara[1500] == 0)
    {
        if(x < y && x < z)
        {
            ara[k] = x;
            k++;
            a++;
            x = ara[a] * 2;
            //k++;
        }
        else if(y < x && y < z)
        {
            ara[k] = y;
            k++;
            b++;
            y = ara[b] * 3;
            //k++;
        }
        else if(z < x && z < y)
        {
            ara[k] = z;
            k++;
            c++;
            z = ara[c] * 5;
            //k++;
        }

        if(x == y)
        {
            a++;
            x = ara[a] * 2;
        }
        else if(y == z)
        {
            b++;
            y = ara[b] * 3;
        }
        else if(z == x)
        {
            c++;
            z = ara[c] * 5;
        }
    }
    cout<<"The 1500'th ugly number is "<<ara[1500]<<"."<<endl;

    return 0;
}
