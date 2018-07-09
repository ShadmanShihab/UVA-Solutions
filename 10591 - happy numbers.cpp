#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    FILE *f = fopen("file.txt", "w");
    int t, n, count, i, mod, j;
    cin>>t;
   for(j=1; j<=t; j++)
    {
        cin>>n;
        i=n;

        while(1)
        {

        count = 0;

        while(i > 0)
        {
            mod = i % 10;
            count += (mod*mod);

            i = i / 10;
        }
        i = count;


            if(count < 10)
            {
                if(count == 1){
                    cout<<"Case #"<<j<<": "<<n<<" is a Happy number."<<endl;
                    break;
                }
                else{
                   cout<<"Case #"<<j<<": "<<n<<" is an Unhappy number."<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
