#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1001];
int cost[1001]={0};
int special_nodes[10];
set<int> all_paths_value[10][1001];
//int visited[N];

void dfs(int i,int next,int prev)
{
    all_paths_value[i][next]=all_paths_value[i][prev];
    for(auto x:all_paths_value[i][prev])
    {
        all_paths_value[i][next].
    }
}

int main()
{
    int N,NSP,Q;
    cin>>N>>NSP>>Q;
    
    
    
    for(int i=1;i<N;i++)
    {
        int x;
        cin>>x;
        graph[i+1].push_back(x);
        graph[x].push_back(i+1);

    }
    for(int i=1;i<=n;i++)
    {
        int y;cin>>y;
        cost[i]=y;
    }

    for(int i=0;i<NSP;i++)
    {
        cin>>special_nodes[i];
    }



    return 0;
}