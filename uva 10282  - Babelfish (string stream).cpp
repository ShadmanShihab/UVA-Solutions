#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> m;
    map<string, string>::iterator it;
    string s1, s2, s3;

    getline(cin, s1);
    cout<<s1;
    while(s1 != ""){
        stringstream ss(s1);
        ss>>s1>>s2;

        m[s2] = s1;
        getline(cin, s1);
    }


    while(cin>>s1){
        it = m.find(s1);

        if(it == m.end())
            printf("eh\n");
        else
            cout<<it->second<<endl;
    }
    return 0;
}
