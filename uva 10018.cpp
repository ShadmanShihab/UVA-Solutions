 #include <bits/stdc++.h>
 using namespace std;

 #define MAX 500000

 int main()
 {
     int T, i, j, len, len2, count;
     unsigned long int n, sec_num, sum;
     char s1[MAX], s2[MAX], str[MAX], reverse_sum[MAX];

     scanf("%d", &T);
     while(T--)
     {
        count = 0;
        scanf("%lu", &n);

        while(1)
        {
            count++;
            sprintf(s1, "%lu", n);

            len = strlen(s1);
            for(i=len-1, j=0; i>=0; i--){
                s2[j] = s1[i];
                j++;
            }

            sec_num = atoi(s2);
            sum = n + sec_num;

            sprintf(str, "%lu", sum);

            len2 = strlen(str);

            for(i=0, j=len2-1; i<len; i++, j--){
                reverse_sum[i] = str[j];
            }
            n = sum;

            if(strcmp(reverse_sum, str) == 0){
                printf("%d %lu\n",count, sum);
                break;
            }
        }
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(str, 0, sizeof(str));
        memset(reverse_sum, 0, sizeof(reverse_sum));
     }
     return 0;
}
