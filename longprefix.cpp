#include<bits/stdc++.h>
using namespace std;
struct Trie{
        bool is_leaf;
        unordered_map<char,pair<int,Trie*> > map;
        void insert(string s)
        {
            Trie *curr_trie = this;
            for(int i=0;i<s.length();i++)
            {
                if(curr_trie->map.find(s[i])!=curr_trie->map.end())
                {
                    curr_trie->map[s[i]].first++;
                    
                }
                else
                {
                     curr_trie->map[s[i]].first=1;
                }
                curr_trie->is_leaf = false;
                if(i==s.length()-1)
                {
                    curr_trie->is_leaf = true;
                }
                curr_trie->map[s[i]].second = new Trie;
                curr_trie = curr_trie->map[s[i]].second;
                
            }
        }
    };
int main()
{
    Trie main_trie;
    main_trie.insert("Hrllp");
    main_trie.insert("hello");

    return 0;
}