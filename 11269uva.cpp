#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<pair<int,int> > prbs(n);
        for(auto &p: prbs)
            cin>>p.first;
        for(auto &p: prbs)
            cin>>p.second;

        auto cmp = [](const pair<int,int> &a,const pair<int,int> &b){
            return a.first+max(a.second,b.first)+b.second < b.first+max(b.second,a.first)+a.second ;
        };

        sort(prbs.begin(),prbs.end(),cmp);
        int a_start=0;
        int b_start=0;
        for(auto &p: prbs)
        {
            a_start += p.first;
            b_start = max(a_start,b_start);// B can only start work after A has finished and his previous work is finished
            b_start+=p.second;

        }
        cout<<b_start<<"\n";

    }
    return 0;
}
