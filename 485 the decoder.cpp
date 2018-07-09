#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    char str1[1002];
    char str2[1002];
    int i, len, j;
    while(gets(str1) != NULL)
    {
        len = strlen(str1);
        j=0;
        for(i=0; i<len; i++)
        {
            str2[j] = str1[i]-7;
            j++;
        }
        str2[j] = '\0';
        cout<<str2<<endl;
    }
    return 0;
}
