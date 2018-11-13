//uva 12532 - Interval Product
//segment tree
#include <bits/stdc++.h>
using namespace std;

#define Max 100001
int ara[Max];
int tree[3 * Max];

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = ara[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left] * tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return 1;

    if(b >= i && e <= j)
        return tree[node];

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1 * p2;
}

void update(int node, int b, int e, int i, int newValue)
{
    if(i>e || i<b)
        return;

    if(b == e)
    {
        tree[node] = newValue;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;

    update(left, b, mid, i, newValue);
    update(right, mid+1, e, i, newValue);

    tree[node] = tree[left] * tree[right];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        for(int i=1; i<=n; i++){
            scanf("%d", &ara[i]);

            if(ara[i] > 1)
                ara[i] = 1;
            else if(ara[i] < -1)
                ara[i] = -1;
        }
        init(1, 1, n);


        for(int i=1; i<=k; i++)
        {
            char ch;
            cin>>ch;

            if(ch == 'C')
            {
                int l, v;
                scanf("%d %d", &l, &v);

                if ( v > 1 )
                    v = 1;
                if ( v < -1 )
                    v = -1;

                update(1, 1, n, l, v);
                ara[l] = v;
            }
            else if(ch == 'P')
            {
                int q1, q2;
                scanf("%d %d", &q1, &q2);
                int res = query(1, 1, n, q1, q2);

                if(res == 0)
                    printf("0");
                else if(res > 0)
                    printf("+");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
