#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,s;
    int cs=1;
    while(cin>>c>>s){
        vector<int> v(2*c,0);
        for(int i=0;i<s;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int sum = accumulate(v.begin(),v.end(),0);
        float avg = sum/(float)c;
        double imb = 0.0;
        printf("Set #%d\n",cs++);
        for(int i=0;i<c;i++)
        {
            int j=2*c-i-1;
            imb += abs(v[i]+v[j]-avg);
            printf(" %d:",i);
            if(v[i])
                printf(" %d",v[i]);
            if(v[j]) 
                printf(" %d",v[j]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n",imb);

    }
    return 0;
}

