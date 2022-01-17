#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> abc = {1,2,3};
    abc.push_back(32);
    vector<pair<int,int> > a;
    a.push_back({1,2});
    for(auto c : abc)
    cout<<c;
    return 0;
}