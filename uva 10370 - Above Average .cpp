///uva 10370 - Above Average
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int T, n, students;
    int ara[1010];

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int count = 0;

        for(int i=0; i<n; i++){
            scanf("%d", &ara[i]);
            count += ara[i];
        }

        sort(ara, ara+n);

        /*for(int i=0; i<n; i++)
            cout<<ara[i]<<" ";
        cout<<endl<<count;*/

        double average = (count * 1.0) / n;

        students = 0;

        for(int i=0; i<n; i++){
            if(ara[i] > average)
                students++;
        }

        double percentage = (students * 100 * 1.0) / n;
        printf("%0.3lf%%\n", percentage);
    }
    return 0;
}
