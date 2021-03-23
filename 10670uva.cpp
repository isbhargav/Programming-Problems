/*
 * Y->X (op: /2 and +1) this-> https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1611 
 * Y->X (op: /2 and -1) https://leetcode.com/problems/broken-calculator/
 */
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int nn,m,l;
        cin>>nn>>m>>l;
        vector<pair<int,string> > v;
        while(l--)
        {
            string s;
            cin>>s;

            string name = s.substr(0,s.find(":"));
            s.erase(0,s.find(":")+1);

            int a = stoi(s.substr(0,s.find(",")));
            s.erase(0,s.find(",")+1);

            int b = stoi(s);

            int  n=nn;
            int sum=(n-m)*a;
             /* This also works */
            /* while(true) */
            /* { */
            /*     if(floor(n/2.0) < m) */
            /*     { */
            /*         sum+=(n-m)*a; */
            /*         break; */       
            /*     } */
            /*     else */
            /*     { */
            /*         sum+=(floor(n/2.0)*a<b)?ceil(n/2.0)*a:b; */
            /*         n=floor(n/2.0); */
            /*     } */

            /* } */
            for(int c=0;n>=m;c++,n/=2)
            {
                int rem = n-m;
                int res= rem*a+c*b;
                sum=min(sum,res);
            }
            v.push_back({sum,name});
        }
        printf("Case %d\n",i);
        sort(v.begin(),v.end());
        for(pair<int,string> p: v)
            cout<<p.second<<" "<<p.first<<"\n";
    }
    return 0;
}
