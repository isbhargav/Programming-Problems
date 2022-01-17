#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int &x: v)
            cin>>x;

        // you can always take first coin as its min
        int sum=v[0];
        int cnt=1;
        for(int i=1;i<n-1;i++)
        {
            // 1+2<4(you can take 2) | 1+2>=3(you cant take 2)
            if(sum+v[i]<v[i+1])
                sum+=v[i],cnt++;
        }
        // you can alwys take last coin
        cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
