#include<iostream>
 #include<cstdio>
 #include<cmath>
 #include<cstring>
 #include<algorithm>
 using namespace std;
 int a[1005];

 int main()
 {
     freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
     int test, n, i, j, d, s, sum, med;
     scanf("%d", &test);
     while(test--)
     {
         scanf("%d", &n);
         for(i=1; i<=n; i++)
         {
             scanf("%d", &a[i]);
         }
         sort(a, a+n+1);
         if(n%2==0)
         {
             d=n/2;
             med=a[d];
         }
         else
         {
             d=(n/2)+1;
             med=a[d];
         }
         sum=0;
         for(j=1; j<=n; j++)
         {
             s=abs(med-a[j]);
             sum=sum+s;
         }
         printf("%d\n", sum);
     }
 }
