///uva 11559 - Event Planning
#include <bits/stdc++.h>
using namespace std;
#define max 99999999
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int participant, budget, hotel, weeks, price, cost, ans, test;

    while(scanf("%d %d %d %d", &participant, &budget, &hotel, &weeks) == 4)
    {
        test = 99999999;
        for(int i=0; i<hotel; i++)
        {
            scanf("%d", &price);
            cost = 0;
            for(int i=0; i<weeks; i++)
            {
                int bed;
                scanf("%d", &bed);

                if(bed >= participant){
                    cost = price * participant;
                    //cout<<"cost = "<<cost<<endl;

                    if(test > cost)
                        test = cost;
                    //cout<<"test = "<<test<<endl;
                }
            }
        }

        if(test>budget || test==0)
            printf("stay home\n");
        else
            printf("%d\n", test);

        test = max;
    }
    return 0;
}
