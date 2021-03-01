#include <bits/stdc++.h>

using namespace std;
int main()
{
    int m,n;

    while(cin>>m>>n,!(m==0 && n==0))
    {
        vector<pair<int,int> > teams(m);
        vector<pair<int,int> > tables(n);
        vector<vector<int> > sol(m+1,vector<int>());
        vector<int> table_space(n+1);
        
        int x;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            teams.push_back({x,i+1});
        }
        for(int i=0;i<n;i++)
        {
            cin>>x;
            tables.push_back({x,i+1});
            table_space[i+1]=x;
        }

        sort(teams.rbegin(),teams.rend());
        sort(tables.rbegin(),tables.rend());
        bool flag=true;

        for(int i=0;i<teams.size();i++)
        {
            int team_members = teams[i].first;
            int team_id = teams[i].second;
            
            for(int j=0;j<tables.size() && team_members>0;j++)
            {
                int table_id=tables[j].second;
                if(team_members && table_space[table_id])
                {
                    table_space[table_id]--;
                    sol[team_id].push_back(table_id);
                    team_members--;
                }
            }
            if(team_members)
            {
                printf("0\n");
                flag=false;
                break;
            }
        }
        if(flag)
        {
            printf("1\n");
            for(int i=1;i<sol.size();i++)
            {
                sort(sol[i].begin(),sol[i].end());
                for(int j=0;j<sol[i].size();j++)
                {
                    int p =sol[i][j];
                    printf("%d",p);
                    if(j<sol[i].size()-1)
                        printf(" ");

                }
                printf("\n");

            }
        }
        
        
    }
    return 0;
}
