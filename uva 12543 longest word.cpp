#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[110], word[110], longest[110];
    int i, j, len, max_len=0, k;
    while(cin>>str)
    {
        if(strcmp(str, "E-N-D") == 0)
            break;

        j=0;
        for(i=0; str[i] !=0; i++){
            if(isalpha(str[i])){
                word[j] = tolower(str[i]);
                j++;
            }
            else if(str[i] == '-'){
                word[j] = str[i];
                j++;
            }
        }
        word[j] = '\0';

        len = strlen(word);

        if(len>max_len){
            max_len = len;

            k=0;
            for(i=0; word[i]!=0; i++){
                longest[k] = word[i];
                k++;
            }
        }
        longest[k] = '\0';
        memset(str, 0, sizeof(str));
        memset(word, 0, sizeof(word));

    memset(str, 0, sizeof(str));
    memset(word, 0, sizeof(word));

    }
    printf("%s\n", longest);

    return 0;
}
