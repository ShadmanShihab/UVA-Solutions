//uva 10656 - Maximum Sum II
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

	vector<int> V;
	int n, temp;

	while(scanf("%d", &n))
    {
        if(n == 0)
            break;

        for(int i=0; i<n; i++)
        {
            scanf("%d", &temp);
            if(temp > 0)
                V.push_back(temp);
        }

        if(V.size() == 0)
            printf("0\n");
        else
        {
            for(int i=0; i<V.size(); i++)
            {
                printf("%d", V[i]);

                if(i != V.size()-1)
                    printf(" ");
            }
            printf("\n");
        }
        V.clear();
    }
	return 0;
}
