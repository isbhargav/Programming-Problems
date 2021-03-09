#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    string s;
    cin>>s;
    unordered_map<char,vector<int> > dict;
    for(int i=0;i<s.length();i++)
        dict[s[i]].push_back(i);

    int q;
    cin>>q;
    while(q--)
    {
        string sub;
        cin>>sub;
        int i=0;
        vector<int> ans(sub.length());
        int last_char_at =-1;
        for(char c: sub)
        {
            auto it = upper_bound(dict[c].begin(),dict[c].end(),last_char_at);
            if(it!=dict[c].end())
            {
                last_char_at = *it;
                ans[i++]=*it;
            }
            else
            {
                // break out not match
                printf("Not matched\n");
                goto done;
            }

        }
        printf("Matched %d %d\n",ans[0],ans[sub.length()-1]);
            done: ;

    }
    return 0;
}
