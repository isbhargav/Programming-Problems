#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    int casw=1;
    while(cin>>n>>q,!(n==0 && q==0))
    {
        printf("CASE# %d:\n",casw++);
        vector<int> v(n);
        for(int &a:v)
            cin>>a;
        sort(v.begin(),v.end());
        for(int i=0;i<q;i++)
        {
            int b;
            cin>>b;
            auto it = lower_bound(v.begin(),v.end(),b);
            if(it==v.end() || *it!=b)
            {
                printf("%d not found\n",b);
            }
            else
            {
                printf("%d found at %d\n",b,(it-v.begin()+1));
            }

        }



    }
    return 0;
}
