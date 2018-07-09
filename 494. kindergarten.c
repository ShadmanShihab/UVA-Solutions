#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[10000];
    char word[1000];

    while(gets(str) != NULL)
    {
        int count = 0;
        int len = strlen(str);
        int i, j=0;

        for(i=0; i<len; i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            {
                word[j] = str[i];
                j++;
            }

            else if(j > 0)
            {
                count++;
                j=0;
            }
            word[j] = '\0';
        }
        if(j>0){
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}

