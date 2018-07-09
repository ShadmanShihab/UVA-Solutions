#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>
#include <iostream>
using namespace std;

int main()
{
    freopen("shihab.txt", "r", stdin);

    set <string> str;

    string s1, s2, s3;
    int i, j, len;

    while(getline(cin, 100) != NULL){

        len = s1.size();

        for(i=0; i<len; i++){

                if(ispunct(s1.at(i))){
                    s1.at(i) = ' ';
                    //len = s1.size();
                    }
                else if(isdigit(s1.at(i))){
                    s1.at(i) = ' ';
                    //len = s1.size;
                }
                else if(isupper(s1.at(i))){
                    s1.at(i) = s1.at(i) + 32;
                    //s1[i] = s1[i] - 32;
                }
            }
        }
        cout<<s1<<endl;
        len = s1.size();
        j=0;
        for(int i=0; i<len; i++){
            if(s1.at(i) != ' '){
                s2 += s1.at(i);
                j++;
            }
            else{
                cout<<s2<<endl;
                str.insert(s2);
                s2.erase();
                j=0;
            }
        }
        if(j > 0){
            str.insert(s2);
                s2.erase();
        }
        cout<<s2<<endl;

}
