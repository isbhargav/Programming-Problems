#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        vector<int> a(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
                if(a[j]<=a[i])
                    sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}