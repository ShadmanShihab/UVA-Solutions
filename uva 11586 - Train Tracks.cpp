//uva 11586 - Train Tracks
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        string str;

        getline(cin, str);

        int len = str.size();

        int male = 0, female = 0;

        for(int i=0; i<len; i++)
        {
            if(str[i] == 'M')
                male++;
            else if(str[i] == 'F')
                female++;
        }
        if(len <= 3)
            printf("NO LOOP\n");
        else if(male == female)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }
    return 0;
}
