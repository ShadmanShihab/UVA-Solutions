///uva 10114 - Loansome Car Buyer
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int duration, noOfDepreciation;
    double loan, downPayment;
    double monthlyPayment, carValue, owned;

    while(1)
    {
        double depreciation[110];

        scanf("%d %lf %lf %d", &duration, &downPayment, &loan, &noOfDepreciation);
        if(duration < 0)
            break;

        owned = loan;


        for(int i=0; i<noOfDepreciation; i++){
            int m;
            double percentage;

            scanf("%d %lf", &m, &percentage);

            for(int i=m; i<101; i++){
                depreciation[i] = percentage;
            }
        }

        monthlyPayment = loan / duration;
        owned = loan;
        carValue = (loan + downPayment) * (1 - depreciation[0]);

        int count = 0;

        while(owned > carValue)
        {
            count++;
            owned -= monthlyPayment;
            carValue = carValue * (1 - depreciation[count]);
            //remaining carvalue after deprecitaion is obtained by subtracting from 1
        }

        if(count==1)
            printf("%d month\n", count);
        else
            printf("%d months\n", count);
    }
    return 0;
}
