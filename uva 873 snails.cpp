#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h, u, d, e;
    double in_height, dis_climbed=0, h_after_climbing=0,  h_after_sliding=0, fat_factor=0;
    int count;
    while(cin>>h>>u>>d>>e){
        dis_climbed=0, h_after_climbing=0,  h_after_sliding=0, fat_factor=0;
        if(h==0 && u==0 && d==0 && e==0)
            break;
        count = 0;
        dis_climbed = u;
        fat_factor = (e / 100) * dis_climbed;
        while(1)
        {
            count++;
            in_height = h_after_sliding;

            h_after_climbing = in_height + dis_climbed;
            h_after_sliding = h_after_climbing - d;


            if(dis_climbed < 0){
               h_after_sliding = in_height - d;
            }
            if(h_after_climbing > h){
                cout<<"success on day "<<count<<endl;
                break;
            }
            else if(h_after_sliding < 0){
                cout<<"failure on day "<<count<<endl;
                break;
            }

            dis_climbed -= fat_factor;
        }
    }
    return 0;
}
