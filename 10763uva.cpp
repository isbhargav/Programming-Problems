#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    int t;
    while(scanf("%d",&t),(t!=0))
    {
        vector<pair<int,int>> v;
        vector<pair<int,int>> vt;

        for(int i=0;i<t;i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
            vt.push_back({y,x});
        }

        sort(v.begin(),v.end());
        sort(vt.begin(),vt.end());

        if(v==vt)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
