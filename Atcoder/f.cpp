#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s,t;
vector<vector<pair<pair<int,int>,int>>> ans(3000,vector<pair<pair<int,int>,int>>(3000,{{-1,-1},-1}));
pair<pair<int,int>,int> lcs(int a,int b)
{
    if(a<0||b<0)
        return {{-1,-1},0};
    if(ans[a][b]!={{-1,-1},-1})
        return ans[a][b];
    if(s[a]==t[b])
       {  
           ans[a][b] = ans[a][b].second > (lcs(a-1,b-1).second ? ans[a][b]:(lcs(a-1,b-1));
           return {{a,b},1+ans[a][b].second};

       }
    
    return (lcs(a-1,b).second>=lcs(a,b-1).second?(ans[a-1][b]=lcs(a-1,b)):(ans[a][b-1]=lcs(a,b-1)));
}
int main()
{
    cin>>s>>t;
    pair<pair<int,int>,int>  abc =lcs(s.length()-1,t.length()-1);
     
    while(abc.first.first !=-1 || abc.first.second !=-1)
    {
        cout<<ans[abc.first.first][abc.first.second]<<endl;
    }

}