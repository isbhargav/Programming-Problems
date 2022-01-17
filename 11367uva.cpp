#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = (int) 1e9+7;
typedef pair<int, int>	pii;
typedef pair<int, pii> pipii;

vector<pii>adj[N];        // {v,w}
int dis[N][N];
int n, m;
int p[N];

int dijkstra(int s, int e, int c){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dis[i][j]=INF;

    priority_queue<pipii> pq;  //{cost,curr_fuel,vertex}
    dis[s][0]=0;
    pq.push({0,{0,s}});
     while(!pq.empty()){

        int cost_u = -pq.top().first;
        int curr_fuel = pq.top().second.first;
        int u = pq.top().second.second;

        pq.pop();

        if(u==e)
        {
            return cost_u;
        }
        if(cost_u > dis[u][curr_fuel])
        {
            continue;
        }

        for(int i=0;i<adj[u].size();++i)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;



            //check if you can reach with curr fuel
            if(w<=curr_fuel)
            {
                if(dis[v][curr_fuel-w]>cost_u)
                {
                    dis[v][curr_fuel-w] = cost_u;
                    pq.push({-dis[v][curr_fuel-w],{curr_fuel-w,v}});
                }
            }
            // if you have capicity to take in more fuel
            if(curr_fuel+1<=c)
            {
                if(dis[u][curr_fuel+1]>dis[u][curr_fuel]+p[u])
                {
                    dis[u][curr_fuel+1]=dis[u][curr_fuel]+p[u];
                    pq.push({-dis[u][curr_fuel+1],{curr_fuel+1,u}});

                }
            }
        }
    }
    return dis[e][0];
}

int main (){
	cin>>n>>m;
	
	for(int i = 0 ; i < n ; i++){
		cin>>p[i];
	}
	
	for(int i = 0 ; i < m ; i++){
		int u, v, w;
		
		cin>>u>>v>>w;
		
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	
	int q;
	
cin>>q;
	
	while(q--){
		int c, s, e;
		cin>>c>>s>>e;
		
		int d = dijkstra(s, e, c);
		
		if(d == INF){
			printf("impossible\n");
		}else{
			printf("%d\n", d);
		}
	}
	
	return 0;
}