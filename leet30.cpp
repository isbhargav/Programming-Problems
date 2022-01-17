#include<bits/stdc++.h>
using namespace std;
int nw;
    int wl;
    vector<int> ans;
     bool func(string s,map<string,int> tt)
     {
         for(int i=0;i<s.length();i+=wl)
         {
             string w=s.substr(i,wl);
             if(tt.find(w)==tt.end())
                 return false;
             
             tt[w]--;
             if(tt[w]<0)
                 return false;
             
         }
         return true;
     }
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> dic;
        
        for(string w : words)
        {
            
                dic[w]++;
        }
        int sl=s.length();
         wl=words[0].length();
         nw = words.size();
        for(int i=0;i<=wl*nw;i++)
        {
            map<string,int> tt(dic);
            if(func(s.substr(i,wl*nw),tt))
                ans.push_back(i);
        }
        return ans;
    }
    int main()
    {
        string s="barfoothefoobarman";
    vector<string> wds = {"foo","bar"};
    findSubstring(s,wds);
        return 0;
    }