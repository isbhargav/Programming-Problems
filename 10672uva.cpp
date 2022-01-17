#include<bits/stdc++.h>
#include <deque>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n!=0)
    {
        vector<int> parent(n+1,-1);
        vector<int> degree(n+1,0);
        vector<int> marbels(n+1,0);
        for(int i=0;i<n;i++)
        {
            int v,m,d;
            cin>>v>>m>>d;

            degree[v]=d;
            marbels[v]=m;
            for(int j=0;j<d;j++)
            {
                int c;
                cin>>c;
                parent[c]=v;
            }

        }

        deque<int> q;

        for(int j=1;j<=n;j++)
            if(degree[j]==0)
                q.push_back(j);

        int moves = 0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop_front();

            int p = parent[f];
            if(p==-1)
            {
                /* moves+=marbels[f]-1; */
                continue;
            }
            int m = marbels[f];

            moves+=abs(m-1);

            marbels[p]+=m-1;
            degree[p]--;

            if(degree[p]==0)
                q.push_back(p);

        }
        cout<<moves<<endl;
    }
    return 0;
}
