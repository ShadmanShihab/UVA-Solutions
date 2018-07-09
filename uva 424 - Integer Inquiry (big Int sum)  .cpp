///uva 424 - Integer Inquiry
///big integer sum
#include <bits/stdc++.h>
using namespace std;
#define max 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    char str[max], str2[max], res[max];
    int len1, len2;

    scanf("%s", str);
    len1 = strlen(str);
    reverse(str, str+len1);

    while(1)
    {
        scanf("%s", str2);
        if(strcmp(str2, "0") == 0)
            break;

        len1 = strlen(str);
        len2 = strlen(str2);

        reverse(str2, str2+len2);

        if(len1 < len2){        //making all the digits 0 when both string arnt equal
            for(int i = len1; i<len2; i++){
                str[i] = '0';
            }
            str[len2] = '\0';
            len1 = len2;
        }
        else{
            for(int i=len2; i<len1; i++){
                str2[i] = '0';
            }
            str2[len1] = '\0';
            len2 = len1;
        }

        int carry=0, sum=0;

        for(int i=0; i<len1; i++){
            sum = (str[i] - 48) + (str2[i] - 48) + carry;
            carry = sum / 10;
            sum %= 10;

            res[i] = sum + 48;
        }

        if(carry > 0){
            res[len1] = carry + 48;
            len1++;
        }
        memset(str, 0, sizeof(str));
        memset(str2, 0, sizeof(str2));
        strcpy(str, res);
        memset(res, 0, sizeof(res));
    }
    len1 = strlen(str);
    reverse(str, str+len1);

    printf("%s\n", str);
    return 0;
}
