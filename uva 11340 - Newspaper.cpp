///uva 11340 - Newspaper
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string s, s1;
    map <char,int> m;
    map <char, int>::iterator it;
    char str[10010];

    int T, k;
    scanf("%d", &T);
    while(T--)
    {
        m.clear();
        double sum = 0.00;

        scanf("%d", &k);
        for(int i=0; i<k; i++)  //taking input in map
        {
            int a;
            char ch;
            cin>>ch>>a;
            m[ch] = a;
            //cout<<ch<<" "<<a<<endl;
        }

        //for(it = m.begin(); it!=m.end(); it++)
            //cout<<it->first<<" "<<it->second<<endl;


        int x;
        scanf("%d", &x);
        getchar();
        for(int j=0; j<x; j++)
        {
            gets(str);
            int len = strlen(str);

            for(int i=0; i<len; i++)
            {
                it = m.find( str[i] );
                if(it!=m.end())
                {
                    sum += it->second;
                    //cout<<"sum = "<<sum<<endl;
                }
            }
        }
        printf("%0.2lf$\n", sum/100);
    }
    return 0;
}
