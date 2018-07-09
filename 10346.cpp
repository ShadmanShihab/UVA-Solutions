#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t, n, x, a, rem;

    while(scanf(("%d %d"), &n, &x) != EOF)
    {
        int count = 0, total = 0;;

        while(n > 0)
        {
            count++;
            total++;
            if(count == x){
                n++;
                count = 0;
            }
            n--;
        }
        cout<<total<<endl;
    }
    return 0;
}
