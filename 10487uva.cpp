#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;int t=1;
    while(cin>>n && n)
    {
        vector<int> a(n,0);
        while(n--)
            cin>>a[n];
        
        
        sort(a.begin(),a.end());
        cout << "Case " << t++ << ":" << endl;
        int q;
        cin>>q;
        while(q--)
        {
        int start = 0 , end =a.size();
        int diff = INT_MAX;
        int ans;
        
            int m;
            cin>>m;
            for(int i=0;i<end;i++)
                for(int j=i+1;j<end;j++)
                    if(abs((a[i]+a[j])-m) < diff)
            {
                diff=abs((a[i]+a[j])-m);
                ans = a[i]+a[j];
                if(diff==0)
                    break;
            }

            
            printf("Closest sum to %d is %d.\n", m, ans);
            
        }
        
    }
    return 0;
}