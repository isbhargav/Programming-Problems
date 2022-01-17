#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    vector<int> F(6,0);
    vector<int> f(6,0);
    while(true)
    {
        for(int i=5;i>=0;i--)
            cin>>F[i];

        if(F==f)
            break;

        int cnt=0;
        for(int i=0;i<6;i++){
            if(F[i]>0)
            {
                if(i==0)
                    cnt+=F[i];
                if(i==1)
                {
                    cnt+=F[i];
                    F[5]-=F[i]*11;
                }
                if(i==2)
                {
                    cnt+=F[i];
                    F[4]-=(F[i]*5);
                }
                if(i==3)
                {
                    cnt+=F[i]/4;
                    if(F[i]%4>0)
                    {
                        cnt++;
                        int space_left = 4-(F[i]%4);
                        if(space_left==1)
                        {
                            F[4]--;
                            F[5]-=5;
                        }
                        else if(space_left==2)
                        {
                            F[4]-=3;
                            F[5]-=6;
                        }
                        else if(space_left==3)
                        {
                            F[4]-=5;
                            F[5]-=7;
                        }
                    }

                }
                if(i==4)
                {
                    cnt+=F[i]/6;
                    if(F[i]/6>0)
                    {
                        int space_left=6-(F[i]%6);
                        cnt+=(space_left>0?1:0);
                        F[5]-=space_left*4;
                    }
                }
                if(i==5)
                {
                    for(int j=0;j<5;j++)
                    {
                        if(F[j]<0)
                        {
                            F[i]-=(6-j)*(6-j);
                        }
                    }
                    cnt+=F[i]/36;
                    cnt+=(F[i]%36>0?1:0);
                }
            }
            
        }
        printf("%d\n",cnt);
    }

    return 0;
}
