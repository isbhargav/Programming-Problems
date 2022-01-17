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
        vector<int> v(n);
        for(int &a: v)
            cin>>a;
        sort(v.rbegin(),v.rend());

        int dis=0;
        int i;
        for( i=3;i<n;i+=3)
            dis+=v[i-1];
        if(i==n)
            dis+=v[n-1];
        cout<<dis<<endl;
    }
    return 0;
}
