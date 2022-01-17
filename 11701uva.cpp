#include<bits/stdc++.h>
using namespace std;
int main(){
    double t;
    while(scanf("%lf", &t) == 1)
    {
        if(t == 0 || t==1)
            cout<<"MEMBER\n";
        else
        {
            bool done=false;
            for(int i=0;i<=6;i++) // This loop needs to be run for n+1 decimal points or else it will produce wrong answer???(0.390552)
            {
                int d = (t*3.0);
                if(d==1)
                {
                    cout<<"NON-MEMBER\n";
                    done=true;
                    break;
                }
                t=t*3.0;
                t-= (double)d;
            }
            if(done==false)
                cout<<"MEMBER\n";
        }
    }
    return 0;
}
/*
 * How to convert float to terniary
Keep multiplying the number after decimal by 3 till it becomes 2.0:
 

0.25*2 = 0.50
0.50*2 = 1.00
and the result is in reverse order being .01
*/
