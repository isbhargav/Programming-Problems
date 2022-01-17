#include<bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string s;
    while(cin>>s,s!="0")
    {
        /* cout<<s<<endl; */
        int n=0;
        string uppr="";
        string lwr="";
    
        for(char c: s)
        {
            if(c=='N')
                n++;
            else if(isupper(c))
                uppr+=c;
            else
                lwr+=c;

        }
        if(lwr.empty())
            printf("no WFF possible\n");
        else
        {
            for(int i=0;i<n;i++)
                printf("N");
            for(int i=1,j=0;i<lwr.length()&& j<uppr.length();i++,j++)
                printf("%c%c",uppr[j],lwr[i]);
            printf("%c\n",lwr[0]);
        };
    }
    return 0;
}
/*
 *  The idea is to build iterativly:
 *   smallest WFF: lower_case_letter-> lwr[0]
 *   now to build bigger we can so is
 *                 uppr[0]lwr[1](lwr[0]) 
 *  uppr[1]lwr[2]( uppr[0]lwr[1](lwr[0]) ) 
 *  ....... and so on we will continue to build longer WFF
 *  Now we can also attach any number of N in front of WFF that will increase the length
 */  
