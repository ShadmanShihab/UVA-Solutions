//uva 195 - Anagram
#include <bits/stdc++.h>
using namespace std;

bool comp(char a, char b)
{
    if(tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, len;
    char str[10000];

    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        len = strlen(str);
        sort(str, str+len, comp);
        printf("%s\n", str);

        while(next_permutation(str, str+len, comp))
        {
            printf("%s\n", str);
        }
    }
    return 0;
}
