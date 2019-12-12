#include<bits/stdc++.h>
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

long long int block[22][22][22];
long long int prefix_sum[22][22][22];

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      memset(block,-1,sizeof block);
      memset(prefix_sum,0,sizeof prefix_sum);
      int a,b,c;
      long long int max_score=INT_MIN;
      cin>>a>>b>>c;
      for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
                {            
                    for(int k=0;k<c;k++)
                        {
                    int dd;
                    cin>>dd;block[i][j][k]=dd;
                    prefix_sum[i][j][k]=dd;

                if(k>0)prefix_sum[i][j][k]+=prefix_sum[i][j][k-1];
                if(j>0)prefix_sum[i][j][k]+=prefix_sum[i][j-1][k];
                if(k>0 && j>0)prefix_sum[i][j][k]-= prefix_sum[i][j-1][k-1];

                // if(i>0)
                //     prefix_sum[i][j][k]+=prefix_sum[i-1][j][k];

            }}}

            

            for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            // for(int k=0;k<c;k++)
            for(int j1=j;j1<b;j1++)
            for(int k1=k;k1<c;k1++)

            {
                // long long int subCube = prefix_sum[i1][j1][k1];

                // if(k>0) subCube-= prefix_sum[i1][j1][k-1];
                // if(j>0) subCube-= prefix_sum[i1][j-1][k1];
                // if(j>0 && k>0) subCube+= prefix_sum[i1][j-1][k-1];

                // if(i>0)
                // {
                //     long long int subCube1=0;
                    
                   
                //     subCube-=subCube1;
                // }
                vector<int> nums;
                for(int x=i;x<=i1;x++)
                    {

                     long long int subCube = prefix_sum[x][j1][k1];

                if(k>0) subCube-= prefix_sum[x][j1][k-1];
                if(j>0) subCube-= prefix_sum[x][j-1][k1];
                if(j>0 && k>0) subCube+= prefix_sum[x][j-1][k-1];
                nums.push_back(subCube);


                    }

                    long long int sum = 0, ans = 0; // important, ans must be initialized to 0 
                    for (int i = 0; i < nums.size(); i++) { // linear scan, O(n)

sum += nums[i]; // we greedily extend this running sum

ans = max(ans, sum); // we keep the maximum RSQ overall

if (sum < 0) sum = 0; // but we reset the running sum }
                    }
                
                max_score = max(max_score,ans);
            }
            cout<<max_score<<endl;
            //cout<<max_score;

      
    
  }
  return 0;
}