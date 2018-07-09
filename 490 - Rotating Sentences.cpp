///490 - Rotating Sentences
///ad hoc 2D ara
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string str[101];
    string s;

    int n=0, max = 0;
    while(getline(cin, s))
    {
        str[n] = s;
        n++;
        if(max < s.length())
            max = s.length();
    }

    for(int r=0; r<max; r++){
        for(int c=n-1; c>=0; c--){
            if(r < str[c].length())
                printf("%c", str[c][r]);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
