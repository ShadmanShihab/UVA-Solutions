//uva 10141 Request for Proposal
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, p, r, kase = 0;
    double compliance, cost, d;
    string name, result, str;

    while(1)
    {
        scanf("%d %d\n", &n, &p);
        if(n == 0 && p == 0) break;

        if(kase >= 1)
            printf("\n");
        kase++;

        for(int i = 0; i < n; i++)
            getline(cin, str);

        compliance = 0.0;
        cost = 999999;

        for(int i = 0; i < p; i++)
        {
            getline(cin, name);
            scanf("%lf %d\n", &d, &r);

            for(int i = 0; i < r; i++)
                getline(cin, str);

            if((double) r / p > compliance) {
                compliance = (double) r / p;
                cost = d;
                result = name;
            }
            else if((double) r / p == compliance)
            {
                if(d < cost)
                {
                    compliance = (double) r / p;
                    cost = d;
                    result = name;
                }
            }
        }
        printf("RFP #%d\n", kase);
        cout<<result<<endl;
    }
    return 0;
}
