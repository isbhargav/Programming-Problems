#include<bits/stdc++.h>
#include <string>
#include <vector>
using  namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }
        string first_word = v[0];
        sort(v.begin(),v.end());
        int start=0;
        for(;v[start]!=first_word;start++);

        int scr = v[start].length();
        string last_word = v[start];
        for(int l=(start+1)%n;l!=start;l=(l+1)%n)
        {
            string curr_word = v[l];
            int i=0,j=0;
            while(i<last_word.length() && j<curr_word.length() && last_word[i]==curr_word[j])
            {
                i++,j++;
            }
            int letters_to_type = curr_word.length()-j;//3-2
            scr+=letters_to_type;
            last_word = curr_word;

        }
        printf("%d\n",scr);
        /* for(string w: v) */
        /*     cout<<w<<endl; */
        cout<<v[start]<<"\n";
        for(int l=(start+1)%n;l!=start;l=(l+1)%n)
            cout<<v[l]<<"\n";

    }
    return 0;
}
/* int main() */
/* { */
/*     int t; */
/*     cin>>t; */
/*     while(t--) */
/*     { */
/*         int n; */
/*         cin>>n; */
/*         vector<string> v; */
/*         for(int i=0;i<n;i++) */
/*         { */
/*             string s; */
/*             cin>>s; */
/*             v.push_back(s); */
/*         } */
/*         sort(v.begin(),v.end()); */
/*         int start=0; */
/*         int scr = v[start].length(); */
/*         string last_word = v[start]; */
/*         for(int l=1;l<n;l++) */
/*         { */
/*             string curr_word = v[l]; */
/*             int i=0,j=0; */
/*             while(i<last_word.length() && j<curr_word.length() && last_word[i]==curr_word[j]) */
/*             { */
/*                 i++,j++; */
/*             } */
/*             int letters_to_type = curr_word.length()-j;//3-2 */
/*             scr+=letters_to_type; */
/*             last_word = curr_word; */

/*         } */
/*         printf("%d\n",scr); */
/*         /1* for(string w: v) *1/ */
/*         /1*     cout<<w<<endl; *1/ */
/*         cout<<v[start]<<"\n"; */
/*         for(int l=1;l<n;l++) */
/*             cout<<v[l]<<"\n"; */

/*     } */
/*     return 0; */
/* } */
