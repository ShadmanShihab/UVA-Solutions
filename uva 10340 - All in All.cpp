//uva 10340 - All in All
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string s1, s2;
    while(cin>>s1>>s2)
    {
        int l1 = s1.size();
        int l2 = s2.size();

        bool flag = false, check = true;;
        int index = -1;
        for(int i=0; i<l1; i++)
        {
            for(int j=index+1; j<l2; j++)
            {
                if(s1[i] == s2[j])
                {
                    //cout<<s1[i]<<" -- "<<s2[j]<<" -- "<<j<<endl;
                    index = j;
                    flag = true;
                    break;
                }
                if(j == l2-1){
                    if(s1[i] != s2[j])
                        check = false;
                }
            }
        }
        if(flag && check)
            printf("Yes\n");
        if(!check)
            printf("No\n");
    }
    return 0;
}
