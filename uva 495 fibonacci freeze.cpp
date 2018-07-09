#include <bits/stdc++.h>
using namespace std;
#define Max 100000

string rev(string s1)
{
    string s2="";
    for(int i=s1.length()-1; i>=0; i--)
        s2 += s1[i];
    return s2;
}
string add(string a, string b)
{
    int sum, carry=0, temp;
    string s1, s2, str = "", result;
    s1 = rev(a);
    s2 = rev(b);

    for(int i=0; i<s1.length(); i++)
    {
        if(i<s2.length())
        {
            sum = (s1[i]-48) + (s2[i]-48) + carry;
            temp =sum;
            sum = sum % 10;

            str += (sum + 48);
            carry = 0;
            if(temp>9)
                carry = 1;
            if(i == (s1.length()-1) && carry==1)
                str += '1';
        }
        else{
             sum = (s1[i]-48) + carry;
             carry = 0;

             if(sum>9)
                carry = 1;
            sum = sum % 10;
             if(i == (s1.length()-1) && carry==1)
             {
                str += (sum + 48);
                str += '1';
             }
             else
                str += (sum + 48);
        }
    }
    result = rev(str);

    return result;
}
int main()
{
    int n;
    map<int, string> m;

    m[0] = "0";
    m[1] = "1";
    m[2] = "1";

    for(int i=3; i<=5000; i++){
        m[i] = add(m[i-1], m[i-2]);
    }

    while(cin>>n)
    {
    cout<<"The Fibonacci number for "<<n<<" is "<<m[n]<<endl;
    }
    return 0;
}
