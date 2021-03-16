#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n,q;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d ",&a);
        v.push_back(a);
    }
    cin>>q;
    while(q--)
    {
        int b;
        scanf("%d",&b);
        vector<int>::iterator  it = lower_bound(v.begin(),v.end(),b);
        vector<int>::iterator it2 = upper_bound(v.begin(),v.end(),b);
        if(it!=v.begin())
            cout<<*(--it);
        else
            cout<<'X';
        cout<<" ";        
        if(it2!=v.end())
            cout<<*it2;
        else
            cout<<'X';

        cout<<"\n";        




    }
    return 0;
}
