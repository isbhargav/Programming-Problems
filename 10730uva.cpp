#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;int t=1;
    while(scanf("%d: ",&n) && n)
    {
        vector<int> a(n,0);
        unordered_set<int> seen;
        for(int i=0;i<n;i++)
          {  cin>>a[i];
             
          }

       // sort(a.begin(),a.end());
       bool flg = true;
        for(int i=0;i<a.size()-2;i++)
        {
            seen.insert(a[i]);
            unordered_set<int> seent(seen);
            for(int j=i+1;j<a.size()-1;j++)
            {
                seent.insert(a[j]);
    
                int d = a[j]-a[i];
                int a3 = a[i] + 2*d;
                if(a3>=0 && a3<n && seent.find(a3)==seent.end())
                {
                    cout<<"no"<<endl;
                    flg =false;
                    break;
                }
                
            }
            if(!flg)
                break;
        }
        if(flg)
        cout<<"yes"<<endl;

    }
    return 0;
}