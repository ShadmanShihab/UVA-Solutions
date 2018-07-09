///uva 272 - TEX Quotes
#include <bits/stdc++.h>
using namespace std;
#define Max 10020

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char ch[Max];
    bool flag = true;

    while(gets(ch))
    {
        int len = strlen(ch);
        for(int i=0; i<len; i++){
            if(ch[i]=='"')
            {
                if(flag){
                    printf("``");
                    flag = false;
                }
                else{
                    printf("''");
                    flag = true;
                }
            }
            else
                printf("%c", ch[i]);
        }
        printf("\n");
    }
    return 0;
}
