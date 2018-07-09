///  uva 575 - Skew Binary
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define max 1000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char input[max];
    while(1)
    {
        scanf("%s", input);

        if(strcmp(input, "0") == 0)
            break;

        int sum = 0;
        int len = strlen(input);

        for(int i=0; i<len; i++){
            sum = sum + ((input[i] - 48) * (pow(2, (len - i)) - 1));
        }

        printf("%d\n", sum);
    }
    return 0;
}
