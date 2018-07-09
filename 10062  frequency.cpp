#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char str[1000];
    int ara[129];
    int i, j, n, len;

    int c = 0;

    while(scanf("%s", str) != EOF)
    {
    c++;
    if(c>1){
        cout<<endl;
    }

    for(i=0; i<129; i++)
        ara[i] = 0;

    len = strlen(str);

    for(i=0; i<len; i++)
    {
        int temp = str[i];
        ara[temp] += 1;
    }


    int temp = 1;

        while(temp <= 128){
            for(i=128; i>=32; i--)
            {
                if(ara[i] == temp)
                {
                    cout<<i<<" "<<ara[i]<<endl;
                }
                if(i == 32)
                    temp++;
            }
        }
    }
    return 0;
}
