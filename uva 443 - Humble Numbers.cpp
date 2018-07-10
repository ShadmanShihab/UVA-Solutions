//uva 443 - Humble Numbers
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int ara[5844] = {0};
    ara[1] = 1;
    int n, a=1, b=1, c=1, d=1, w=2, x=3, y=5, z=7, k=2;;

    while(ara[5842] == 0)
    {
        if(w<x && w<y && w<z)
        {
            ara[k] = w;
            k++;
            a++;
            w = ara[a] * 2;
        }
        else if(x<w && x<y && x<z)
        {
            ara[k] = x;
            k++;
            b++;
            x = ara[b] * 3;
        }
        else if(y<w && y<x && y<z)
        {
            ara[k] = y;
            k++;
            c++;
            y = ara[c] * 5;
        }
        else if(z<w && z<x && z<y)
        {
            ara[k] = z;
            k++;
            d++;
            z = ara[d] * 7;
        }
        if(w == x || w == y || w == z)
        {
            a++;
            w = ara[a] * 2;
        }
        else if(x==w || x==y || x==z)
        {
            b++;
            x = ara[b] * 3;
        }
        else if(y==w || y==x || y==z)
        {
            c++;
            y = ara[c] * 5;
        }
        else if(z == w || z == y || z == x)
        {
            d++;
            z = ara[d] * 7;
        }
    }

    while(1)
    {
        scanf("%d", &n);

        if(n == 0)
            break;

        if(n%10==1 && n%100!=11)
            printf("The %dst humble number is %d.\n", n, ara[n]);

        else if(n%10==2 && n%100!=12)
            printf("The %dnd humble number is %d.\n", n, ara[n]);

        else if(n%10==3 && n%100!=13)
            printf("The %drd humble number is %d.\n", n, ara[n]);

        else
            printf("The %dth humble number is %d.\n", n, ara[n]);
    }
    return 0;
}
