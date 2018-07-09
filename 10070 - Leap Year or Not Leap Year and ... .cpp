///uva 10070 - Leap Year or Not Leap Year and ...
#include <bits/stdc++.h>
using namespace std;
#define max 2000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char str[max];
    int i, len, mod4, mod100, mod400, mod55, mod15;
    bool flag = false;

    while(scanf("%s", str) == 1)
    {
        if(flag)
            printf("\n");
        //count = false;

        mod4=0;
        mod100=0;
        mod400=0;
        mod55=0;
        mod15=0;

        len = strlen(str);

        for(i=0; i<len; i++)
        {
            mod4 = (mod4*10 + (str[i] - '0') ) % 4;
            mod100 = (mod100*10 + (str[i]-'0') ) % 100;
            mod400 = (mod400*10 + (str[i]-'0') ) % 400;
            mod15 = (mod15*10 + (str[i]-'0') ) % 15;
            mod55 = (mod55*10 + (str[i]-'0') ) % 55;
        }

        if(mod400==0 ||  (mod4==0 && mod100!=0))
        {
            printf("This is leap year.\n");

            if(mod15 == 0)
                printf("This is huluculu festival year.\n");
            if(mod55 == 0)
                printf("This is bulukulu festival year.\n");
        }
        else if(mod15 == 0)
                printf("This is huluculu festival year.\n");
        else
            printf("This is an ordinary year.\n");

        flag = true;
    }
    return 0;
}
