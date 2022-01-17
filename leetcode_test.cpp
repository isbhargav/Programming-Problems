#include<bits/stdc++.h>
using namespace std;

 int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int ans =0;
        int sign = dividend<0 ^ divisor<0 ? -1:1;
        int div = abs(dividend),d = abs(divisor);
        
        int m=0;
        while(div >= (d<<(m+1)) )
            m++;
        
        div -= (d<<m);
        ans = (1<<m);
        while(div>d)
        ans++;
        return ans*sign;
        
        
    }

int main()
{
    cout<<divide(10,3);
    return 0;
}