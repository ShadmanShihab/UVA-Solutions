///uva 10176 -  Ocean Deep ! - Make it shallow !!
///base conversion && modulas
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char ch;
    char str[10010];
    int n = 131071, num, j;
    int number;

    while(cin>>ch){
        number = 0;

        number = (number*2) + (ch - 48);
        number = number % n;
        while(cin>>ch){
            if(ch=='#')
                break;

            number = (number*2) + (ch - 48);
            number = number % n;
        }

        if(!number)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
