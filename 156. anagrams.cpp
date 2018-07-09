#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;

    string s, temp, real;
    set<string> str;
    set<string> ans;
    map<string, string> m1;
    map<string, int> m2;

    while(cin>>s)
    {
        if(s == "#")
            break;

        real = s;
        len = real.length();
        for(int i=0; i<len; i++){
            if(isalpha(real.at(i)))
                temp += tolower(real.at(i));
        }

        sort(temp.begin(), temp.end());

        m1[real] = temp;
        m2[temp]++;

        real.clear();
        temp.clear();

    }

    for(map<string,int>::iterator it = m2.begin(); it!=m2.end(); it++){
        if(it->second == 1){
            temp = it->first;
        for(map<string,string>::iterator jt = m1.begin(); jt!=m1.end(); jt++){
           if(temp == jt->second)
                ans.insert(jt->first);
            }
        }
    }
    for(set<string>::iterator it = ans.begin(); it!=ans.end(); it++)
        cout<<*it<<endl;
    return 0;
}
