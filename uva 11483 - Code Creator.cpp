//uva 11483 - Code Creator
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int kase = 0, T;
    while(1)
    {
        scanf("%d", &T);
        if(T==0)
            break;
        kase++;

        vector<string> str;
        string s;
        cin.ignore();
        for(int i=0; i<T; i++)
        {
            getline(cin, s);

            str.push_back(s);

        }


        printf("Case %d:\n", kase);


        printf("#include<string.h>\n");
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");

        for(int k=0; k<str.size(); k++)
        {
            printf("printf(\"");
            string line = str[k];
            //int length = line.size();

            for(int i=0; i<line.size(); i++)
            {
                if(line[i] == '\"')
                    printf("\\\"");
                else if(line[i] == '\'')
                    printf("\\\'");
                else if(line[i] == '\\')
                    printf("\\\\");
                else
                    printf("%c", line[i]);
            }
            printf("\\n\");\n");
        }

        printf("printf(\"\\n\");\n");
        printf("return 0;\n");
        printf("}\n");

    }
    return 0;
}
