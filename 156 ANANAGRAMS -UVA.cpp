#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);
    map<string , int>f;
    map<string , int>::iterator _if;
    map<string , string>word;
    set<string>ans;
    set<string>::iterator it;

    char str[MAX];
    string temp, real;

    while(gets(str))
    {
        if(str[0]=='#')
            break;
        for(int i=0;str[i]!=0;i++)
        {
            if(str[i]==32)
            {
                sort(temp.begin(),temp.end());
                word[temp]=real;
                f[temp]++;
                temp.clear();
                real.clear();
                continue;
            }
            else if(str[i]!=32)
            {
                if(isalpha(str[i]))
                    temp.push_back(tolower(str[i]));
                real.push_back(str[i]);
            }
        }

        if(temp.size()!=0)
        {
            sort(temp.begin(),temp.end());
            word[temp]=real;
            f[temp]++;
            temp.clear();
            real.clear();
        }

    }

    for(_if=f.begin();_if != f.end();_if++)
        if(_if->second==1)
            ans.insert(word[_if->first]);

    for(it = ans.begin();it!=ans.end();it++)
        cout<<*it<<endl;

    return 0;
}
