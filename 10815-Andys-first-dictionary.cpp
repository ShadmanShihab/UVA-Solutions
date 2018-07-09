#include <iostream>
#include <stdio.h>
#include <string>
#include <set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    string s;
    string word;
    set<string> str;
    int i, j, len;

    while(getline(cin, s))
    {
        len = s.size();
        for(i=0; i<len; i++){
            if(ispunct(s.at(i))){
                s.at(i) = ' ';
                len = s.size();
            }
            else if(isdigit(s.at(i))){
                s.at(i) = ' ';
                len = s.size();
            }
            else if(s.at(i) >= 'A' && s.at(i) <= 'Z'){
                s.at(i) = s.at(i) + 32;
            }
        }

        len = s.size();


        j=0;
        for(i=0; i<len; i++){
            if(s.at(i) != ' '){
                word += s.at(i);
            }
            else{
                str.insert(word);
                word.clear();
            }
        }
        if(!word.empty())
        {
            str.insert(word);
                word.clear();
        }
    }

    for(set<string>::iterator it = str.begin(); it != str.end(); it++){
       if(it == str.begin())
            continue;
        cout<<*it<<endl;
    }

    return 0;
}
