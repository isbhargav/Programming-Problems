#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
//    cin>>m>>n;
    while(scanf("%d %d",&m,&n),!(m==1 && n==1))
    {
        string s="";
        int l1=0,l2=1;
        int h1=1,h2=0;
        while(true)
        {
            int mid_1 = l1+h1;
            int mid_2 = l2+h2;
            // now check if mid(mid_1/mid_2) > target(m/n)
            if(n*mid_1 > m*mid_2)
            {
                h1 = mid_1;
                h2 = mid_2;
                s+='L';
            }
            else if(n*mid_1 < m*mid_2)
            {
                l1 = mid_1;
                l2 = mid_2;
                s+='R';
            }
            else
                break;

        }
        cout<<s<<"\n";
    }
}
