///uva 401-Palindromes
#include <bits/stdc++.h>
using namespace std;

map<char, char> m;
map<char, char>::iterator it;

bool mirror(char str[])
{
    int len = strlen(str);
    int mid;

    if(len % 2 == 0)
        mid = len / 2;
    else
        mid = (len / 2) + 1;

    for(int i=0; i<mid; i++)
    {
        if(str[len - i - 1] != m[str[i]])
            return false;
    }
    return true;
}

bool palindrome(char str[])
{
    char rev[30];
    //strcpy(rev, str);

    int len = strlen(str);
    int mid;

    if(len % 2 == 0)
        mid = len / 2;
    else
        mid = (len / 2) + 1;


    for(int i=0; i<mid; i++)
    {
        if(str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char Charac[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    char revers[50] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

    for(int i=0; i<35; i++)
        m[Charac[i]] = revers[i];

    char str[30];
    while(cin>>str)
    {
        bool m = mirror(str);
        bool p = palindrome(str);

        if(!m && !p)
            printf("%s -- is not a palindrome.\n", str);
        else if(m && p)
            printf("%s -- is a mirrored palindrome.\n", str);
        else if(m && !p)
            printf("%s -- is a mirrored string.\n", str);
        else if(!m && p)
            printf("%s -- is a regular palindrome.\n", str);

        printf("\n");
    }
    return 0;
}
