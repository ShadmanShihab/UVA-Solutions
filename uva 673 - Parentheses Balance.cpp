///uva 673 - Parentheses Balance
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char str[10000];
    int T;
    scanf("%d", &T);
    cin.ignore();

    while(T--)
    {
        stack<char> S;
        bool flag = true;

        gets(str);

        int len = strlen(str);

        if(len == 0)
            flag = true;

        else if(len % 2 != 0){
            flag = false;
        }
        else{
            for(int i=0; i<len; i++)
            {
                if(str[i] == ' ')
                    continue;

                if(str[i] == '(' || str[i] == '[')
                    S.push(str[i]);

                else{
                    if(S.size() == 0){
                        flag = false;
                        break;
                    }

                    char top = S.top();

                    if((str[i]==')' && top!='(') || (str[i]==']' && top!='[')){
                        flag = false;
                        break;
                    }
                    S.pop();
                }
            }
        }
        if(S.size() > 0)
            flag = false;

        if(!flag)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
