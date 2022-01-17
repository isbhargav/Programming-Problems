#include<bits/stdc++.h>
using namespace std;
int main()
{

    int y,p;
    while(scanf("%d %d", &y, &p) != EOF){
        vector<int> v(p,0);
        for(int i=0;i<p;i++)
        {
            cin>>v[i];
        }
        int ans=0,start,end;
        for(auto it = v.begin();it!=v.end();it++)
        {
            int target = *it+y-1;
            auto it2 = upper_bound(v.begin(),v.end(),target);
            int curr = it2-it;
            if(ans<curr)
            {
                ans=curr;
                start = *(it);
                end = *(--it2);

            }

        }
        cout<<ans<<" "<<start<<" "<<end<<"\n";
    }
    return 0;
}
