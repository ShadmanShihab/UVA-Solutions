//uva 10252 - Common Permutation

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        int l1 = s1.length();
        int l2 = s2.length();

        int ara1[30], ara2[30];
        memset(ara1, 0, sizeof(ara1));
        memset(ara2, 0, sizeof(ara2));

        for(int i=0; i<l1; i++)
            ara1[s1[i] - 97]++;

        for(int i=0; i<l2; i++)
            ara2[s2[i] - 97]++;

        int index;
        for(int i=0; i<26; i++)
        {
            if(ara1[i]>0 && ara2[i]>0)
            {
                if(ara1[i] < ara2[i])
                    index=ara1[i];
                else
                    index=ara2[i];

                for(int j=0; j<index; j++)
                    printf("%c", i+97);
            }
        }
        printf("\n");
    }
    return 0;
}
