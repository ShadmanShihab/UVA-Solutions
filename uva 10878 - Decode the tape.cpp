//uva 10878 - Decode the tape
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int value[] = {128, 64, 32, 16, 8, 4, 2, 1};
    char str[100], str2[100];

    gets(str);
    gets(str);

    while(str[0] == '|')
    {
        int Count = 0;

        int k=0;
        int len = strlen(str);

        for(int i=0; i<len; i++)
        {
            if(str[i] == 'o' || str[i] == ' '){
                str2[k] = str[i];
                k++;
            }
        }

        for(int i=7; i>=0; i--)
        {
            if(str2[i] == 'o')
                Count += value[i];
        }
        printf("%c", Count);

        gets(str);
    }
    return 0;
}
