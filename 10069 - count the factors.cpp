#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size = 100000;
    int prime[size];
    int factor[size];
    int number, root,temp;

    while(1)
    {
        cin>>number;
        if(number == 0)
            break;
        temp = number;

        for(int i=1; i<=size; i++)
            prime[i] = i;

        prime[0] = 0;
        prime[1] = 0;
        root = sqrt(number);

        for(int i=2; i<=root; i++)
            for(int j=2; i*j < size; j++)
                prime[i*j] = 0;

        int count = 0;

        for(int i=0; i<=root; i++)
        {
            if(prime[i])
            {
                if(number % prime[i] == 0)
                {
                    while(number % prime[i] == 0)
                        number = number / prime[i];
                    count++;
                }
            }
        }
        if(number != 1)
            count++;
        cout<<temp<<" : "<<count<<endl;
    }
    return 0;
}
