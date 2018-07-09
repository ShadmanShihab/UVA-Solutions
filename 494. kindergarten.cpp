#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string str;

    while(getline(cin, str) != NULL)
    {
        int count = 0;
        //cout<<str;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == ' ')
                count++;
        }
        cout<<count+1<<endl;
    }
}
