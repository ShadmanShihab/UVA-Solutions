#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{

    int c;
    vector<string> v;
    map<string, string> m;
    map<string, string>::iterator it;
    string s, s2, temp;
    while(cin>>s)
    {
        if(s == "XXXXXX")
            break;
        temp = s;
        sort(temp.begin(), temp.end());

        m[s] = temp;
    }
    while(cin>>s2)
    {
        if(s2 == "XXXXXX")
            break;
        sort(s2.begin(), s2.end());
        v.push_back(s2);
    }
    for(int i=0; i<v.size(); i++){
        c=0;
        for(it=m.begin(); it!=m.end(); it++){
            if(v[i] == it->second){
                cout<<it->first<<endl;
                c=1;
            }
        }
        if(c==0){
            cout<<"NOT A VALID WORD\n";
            c=0;
        }
        cout<<"******"<<endl;
    }
    return 0;
}
