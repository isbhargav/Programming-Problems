#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int d,n;
        cin>>d>>n;
        int k=1;
        int max_node = (1<<d)-1;
       int  parent = 1;
        while(k<=max_node)
        {
            parent=k;
            if(n&1)
                k=(k<<1);
            else
                k=(k<<1)+1;
            n=(n+1)/2;
        }

//        for(int i=0;i<d-1;i++)
//        {
//            if(n&1)
//                k=(k<<1);
//            else
//                k=(k<<1)+1;
//            n=(n+1)/2;
//        }
        cout<<parent<<"\n";
    }
    return 0;

}
/*
 *
 *
 * d=4,n=2 k=1
 * 1: 2=even => (k=3) (n=1)
 * 2: 1=odd => (k=6) (n=1)
 * 3: 1=odd => (k=12) (n=1)
 */
