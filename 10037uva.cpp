#include <bits/stdc++.h>
using namespace std;
vector<int> times(1000);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> times[i];
        }
        sort(times.begin(), times.begin() + n);

        int i = n-1;
        int total_time=0;
        while(true)
        {
            if(i==0)
            {
                total_time+=times[0];
                break;
            }
            else if(i==1)
            {
                total_time+=(times[1]);
                break;
            }
            else if(i==2)
            {
                total_time+=(times[1]+times[0]+times[2]);
                break;
            }
            else if (i>=3)
            {
                if(2*times[0]+times[i-1]+times[i]<times[0]+2*times[1]+times[i])
                {
                    // f1 should take both
                    total_time+=(2*times[0]+times[i-1]+times[i]);
                }
                else
                {
                    //f1,f2 goes first
                    total_time+=(times[0]+2*times[1]+times[i]);
                }
                i-=2;
            }
        }
        printf("%d\n",total_time);
        i=n-1;
        total_time=0;
        while(true)
        {
            if(i==0)
            {
                printf("%d\n",times[0]);
                total_time+=times[0];
                break;
            }
            else if(i==1)
            {
                printf("%d %d\n",times[0],times[1]);
                total_time+=(times[1]+times[0]);
                break;
            }
            else if(i==2)
            {
                printf("%d %d\n",times[0],times[1]);
                printf("%d\n",times[0]);
                printf("%d %d\n",times[0],times[2]);
                total_time+=(times[1]+times[0]+times[2]);
                break;
            }
            else if (i>=3)
            {
                if(2*times[0]+times[i-1]+times[i]<times[0]+2*times[1]+times[i])
                {
                    // f1 should take both
                    printf("%d %d\n",times[0],times[i-1]);
                    printf("%d\n",times[0]);
                    printf("%d %d\n",times[0],times[i]);
                    printf("%d\n",times[0]);
                    total_time+=(2*times[0]+times[i-1]+times[i]);

                }
                else
                {
                    //f1,f2 goes first
                    printf("%d %d\n",times[0],times[1]);
                    printf("%d\n",times[0]);
                    printf("%d %d\n",times[i-1],times[i]);
                    printf("%d\n",times[1]);
                    total_time+=(times[0]+2*times[1]+times[i]);
                }
               i-=2;
            }
        }
        if (t)
            cout << endl;
    }
    return 0;
}
