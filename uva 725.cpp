 #include <bits/stdc++.h>
 using namespace std;

 int main()
 {

     int abcde, i, j, n, k, count=0, a;
     char s1[10], s2[10], s[10];
     set<int> str;

     while(1)
     {
         a = 0;

         scanf("%d", &n);

         if(n==0)
            break;

         if(count==1)
            printf("\n");
        count = 0;
         for(i=1000; i<=99999; i++){
            abcde = i*n;
            if(abcde > 99999)
                break;

            if(abcde>=10000){

            sprintf(s1, "%d", abcde);
            sprintf(s2, "%d", i);

            if(i<=9999)
                str.insert(0);

            for(j=0; s1[j]!=0; j++)
                str.insert(s1[j] - 48);

            for(j=0; s2[j]!=0; j++)
                str.insert(s2[j] - 48);


            if(str.size() == 10){
                if(i <= 9999){
                    printf("%d / 0%d = %d\n", abcde, i, n);
                }
                else{
                    printf("%d / %d = %d\n", abcde, i, n);
                }
                a=1;
            }
            str.clear();
            }
         }
        if(a==0)
            printf("There are no solutions for %d.\n", n);

        count++;
     }
     return 0;
 }

