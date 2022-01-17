// Credits https://github.com/justadreamer/uva-solutions/blob/master/uva10755/uva10755.cpp
#include<bits/stdc++.h>
/* #include<assert.h> */
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

long long int prefix_sum[22][22][22];

long long subCube(vector<int> p1,vector<int> p2)
{
    /*
     *  Get Sum of SubCube between p1 and p2.
     *  Make sure that points in p1 <= p1
     */
    int i=p1[0],j=p1[1],k=p1[2];
    int i1=p2[0],j1=p2[1],k1=p2[2];

    assert(i<=i1);
    assert(j<=j1);
    assert(k<=k1);

    long long int ans = prefix_sum[i1][j1][k1];
    if(i>0)                ans -= prefix_sum[i-1][j1][k1];
    if(j>0)                ans -= prefix_sum[i1][j-1][k1];
    if(k>0)                ans -= prefix_sum[i1][j1][k-1];
    if(i>0 && j>0)         ans += prefix_sum[i-1][j-1][k1];
    if(i>0 && k>0)         ans += prefix_sum[i-1][j1][k-1];
    if(k>0 && j>0)         ans += prefix_sum[i1][j-1][k-1];
    if(i>0 && j>0 && k>0)  ans -= prefix_sum[i-1][j-1][k-1];

    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        /* memset(block,-1,sizeof block); */
        /* memset(prefix_sum,0,sizeof prefix_sum); */
        int a,b,c;
        long long int max_score=INT_MIN;
        cin>>a>>b>>c;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {            
                for(int k=0;k<c;k++)
                {
                    long long int dd;
                    cin>>dd;
                    prefix_sum[i][j][k]=dd;

                    if(i>0)                prefix_sum[i][j][k]+=prefix_sum[i-1][j][k];
                    if(j>0)                prefix_sum[i][j][k]+=prefix_sum[i][j-1][k];
                    if(k>0)                prefix_sum[i][j][k]+=prefix_sum[i][j][k-1];
                    if(i>0 && j>0)         prefix_sum[i][j][k]-= prefix_sum[i-1][j-1][k];
                    if(i>0 && k>0)         prefix_sum[i][j][k]-= prefix_sum[i-1][j][k-1];
                    if(k>0 && j>0)         prefix_sum[i][j][k]-= prefix_sum[i][j-1][k-1];
                    if(i>0 && j>0 && k>0)  prefix_sum[i][j][k]+=prefix_sum[i-1][j-1][k-1];

                }}}
        for(int i=0;i<a;++i) for(int j=0;j<b;++j) for(int k=0;k<c;++k)
            for(int i1=i;i1<a;++i1) for(int j1=j;j1<b;++j1) for(int k1=k;k1<c;++k1)
            {

                max_score = max(max_score,subCube({i,j,k},{i1,j1,k1}));
            }


        cout<<max_score<<endl;
        if(t)cout<<endl;

    }
    //cout<<max_score;



    return 0;
}
