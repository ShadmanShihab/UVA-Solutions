///uva 11942 - Lumberjack Sequencing
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    bool p=true;

    while(T--)
    {
        int ara[11];
        for(int i=0; i<10; i++)
            scanf("%d", &ara[i]);
        bool flag = true;

        if(ara[0] > ara[1])
        {
            for(int i=1; i<9; i++)
            {
                if(ara[i] > ara[i+1])
                    continue;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            for(int i=1; i<9; i++)
            {
                if(ara[i] < ara[i+1])
                    continue;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(p)
        {
            printf("Lumberjacks:\n");
            p = false;
        }
        if(flag)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
