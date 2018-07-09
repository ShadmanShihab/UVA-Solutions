///uva 146 - ID Codes
///next permutation
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define Max 1000

int main ()
{
    char str[Max];
    while(1)
    {
        scanf("%s", str);

        if(str[0] == '#')
            break;
        int len =strlen(str);

        if( next_permutation(str, str+len))
            printf("%s\n", str);
        else
            printf("No Successor\n");
    }
    return 0;
}
