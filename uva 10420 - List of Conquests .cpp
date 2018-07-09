/// uva 10420 - List of Conquests
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    map<string, int> m;
    map<string, int>::iterator it;

    int T;
    scanf("%d", &T);
    string visited[100];
    string country, girls;

    while(T--)
    {
        cin>>country;
        getline(cin, girls);

        it = m.find(country);
        if(it == m.end())
        {
            m[country] = 1;
        }
        else
        {
            m[country]++;
        }
    }
    for(it=m.begin(); it!=m.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;

    return 0;
}
