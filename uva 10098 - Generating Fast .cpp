//uva 10098 - Generating Fast
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, len;
    char str[11];

    scanf("%d", &T);


    while(T--)
    {
        cin>>str;
        len = strlen(str);

        sort(str, str+len);
        printf("%s\n", str);

        while(next_permutation(str, str+len))
        {
            printf("%s\n", str);
        }

        printf("\n");
    }
    return 0;
}
