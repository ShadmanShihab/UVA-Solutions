//uva 10945 - Mother bear
#include <bits/stdc++.h>
using namespace std;

#define Max 10000

int main()
{
    char str[Max], sentence[Max], reverse_sentence[Max];
    int len1, len2, k, i, j;
    while(1)
    {
        gets(str);

        if(strcmp(str, "DONE") == 0)
            break;

        len1 = strlen(str);

        k = 0;
        for(i=0; i<len1; i++)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                sentence[k] = str[i];
                k++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                sentence[k] = str[i] + 32;
                k++;
            }
        }
        sentence[k] = '\0';

        len2 = strlen(sentence);

        for(i=0, j=len2-1; i<len2; i++, j--)
            reverse_sentence[i] = sentence[j];

        reverse_sentence[i] = '\0';

        if(strcmp(sentence, reverse_sentence) == 0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
