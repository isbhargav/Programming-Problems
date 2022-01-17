#include<bits/stdc++.h>
#include <cctype>
#include <string>
using namespace std;
vector<long long int> evaulate(vector<long long int> &ex,int oprand)
{
    vector<long long int> st;
        for(auto c: ex)
            if(c==(oprand))
            {
                long long int a = st.back();st.pop_back();
                long long int b = st.back();st.pop_back();
                st.push_back(a+b);

            }
            else
            {
                st.push_back(c);
            }
        return st;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string  s;
        cin>>s;
        vector<long long int> express;

        for(int i=0;i<s.length();)
        {
            if(isdigit(s[i]))
            {
                //check next is also digit
                int last_d = s[i]-'0';
                if(i+1<s.length() && isdigit(s[i+1]))
                {
                    int d = last_d*10+s[i+1]-'0';
                    express.push_back(d);
                    i+=2;
                }
                else
                {
                    express.push_back(last_d);
                    i++;
                }
            }
            else {
                express.push_back(0-s[i]);
                i++;
            }
        }
        vector<long long int> Min(express);
        vector<long long int> Max(express);

        for(int i=1;i<Max.size();i++)
            if(Max[i-1]==(0-'+'))
                swap(Max[i-1],Max[i]);
        vector<long long int> sub = evaulate(Max,0-'+');
        for(int i=1;i<sub.size();i++)
            if(sub[i]==(0-'*'))
                swap(sub[i-1],sub[i]);
        vector<long long int> sub2 = evaulate(sub,0-'*');

        for(int i=1;i<Min.size();i++)
            if(Min[i-1]==(0-'*')) 
                swap(Min[i-1],Min[i]);
        vector<long long int> sub1 = evaulate(Min,0-'*');
        for(int i=1;i<sub1.size();i++)
            if(sub1[i-1]==(0-'+'))
                swap(sub1[i-1],sub1[i]);

        vector<long long int> sub3 = evaulate(sub1,0-'+');

        printf("The maximum and minimum are %lld and %lld.\n",sub2[0],sub3[0]);
    }
    return 0;
}
