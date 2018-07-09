#include <stdio.h>
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, r, c, sum, sum2, k, l, x=0, y=0, a, b;
    int ara[100][100], rowsum[1000], colsum[1000];
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        for(r=0; r<n; r++)
            for(c=0; c<n; c++)
                scanf("%d", &ara[r][c]);

        for(r=0; r<n; r++){
            sum = 0;
            for(c=0; c<n; c++)
                sum += ara[r][c];
            rowsum[r] = sum;
        }

       for(c=0; c<n; c++){
            sum = 0;
            for(r=0; r<n; r++)
                sum += ara[r][c];
            colsum[c] = sum;
        }

        k=0;
        l=0;
        a=0;
        b=0;



        for(r=0; r<n ;r++)
        {
            if(rowsum[r] % 2 == 0)
                k++;

            else if(rowsum[r] % 2 == 1){
                x = r+1;
                a = a + 1;
            }
        }

        for(r=0; r<n ;r++)
        {
            if(colsum[r] % 2 == 0)
                l++;

            else if(colsum[r] % 2 == 1){
                y = r+1;
                b = b + 1;
            }
        }

        if(k == n && l == n)
            printf("OK\n");
        else if(a == 1 && b == 1)
            printf("Change bit (%d,%d)\n", x, y);
        else
            printf("Corrupt\n");
    }
    return 0;
}

