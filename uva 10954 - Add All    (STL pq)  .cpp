///uva 10954 - Add All
///STL priority queue
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    while(1)
    {
        bool flag = false;

        scanf("%d", &n);
        if(n==0) break;

        priority_queue<ull, vector<ull>, greater<ull> > pq;
        while(n--)
        {
            ull a;
            scanf("%llu", &a);

            pq.push(a);
        }

        ull add = 0, count = 0;

        while(pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            add = a + b;
            count+=add;
            pq.push(add);
        }
        printf("%llu\n", count);
    }
    return 0;
}
