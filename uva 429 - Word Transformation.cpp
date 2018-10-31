//uva 429 - Word Transformation
#include <bits/stdc++.h>
using namespace std;

map<string, int> level;
map<string, vector<string> > adj;
map<string, vector<string> >::iterator it;

int bfs(string start, string des)
{
    level[start] = 0;
    queue<string> Q;
    Q.push(start);

    while(!Q.empty())
    {
        string u = Q.front();
        Q.pop();

        if(u == des)
            return level[des];

        for(int i=0; i<adj[u].size(); i++)
        {
            string v = adj[u][i];

            if(!level.count(v))
            {
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        adj.clear();
        string str, temp;
        int s, diff;

        while(cin>>str)
        {
            if(str == "*")
                break;
            adj[str];

            for(it = adj.begin(); it!=adj.end(); it++)
            {
                temp = it->first;
                s = temp.size();
                diff = 0;

                if(s == str.size())
                {
                    for(int i=0; i<s &&  diff<2; i++)
                    {
                        if(str[i] != temp[i])
                            diff++;
                    }
                }
                if(diff == 1)
                {
                    adj[str].push_back(temp);
                    adj[temp].push_back(str);
                }
            }
        }

        getchar();
        string text;
        while(getline(cin, text))
        {
            level.clear();
            if(text == "")
                break;

            int position;
            string start, des;

            position = text.find(" ");
            start = text.substr(0, position);
            des = text.substr(position+1, text.size());

            cout<<start<<" "<<des<<" "<<bfs(start, des)<<endl;
        }
        if(T)
            printf("\n");
    }
    return 0;
}
