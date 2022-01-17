struct Trie
{
    bool is_leaf;
    unordered_map<char, pair<int, Trie *>> map;

    string find_max_prefix(int total)
    {
        int score = 1;
        string s = "";
        Trie *curr_trie = this;
        unordered_map<char, pair<int, Trie *>>::iterator itr;
        for (itr = curr_trie->map.begin(); itr != curr_trie->map.end(); itr++)
        {
            if (itr.second)
            {
            }
        }
    }
    void insert(string s)
    {
        Trie *curr_trie = this;
        for (int i = 0; i < s.length(); i++)
        {
            if (curr_trie->map.find(s[i]) != curr_trie->map.end())
            {
                curr_trie->map[s[i]].first++;
            }
            else
            {
                curr_trie->map[s[i]].first = 1;
            }
            curr_trie->is_leaf = false;
            if (i == s.length() - 1)
            {
                curr_trie->is_leaf = true;
            }
            curr_trie->map[s[i]].second = new Trie;
            curr_trie = curr_trie->map[s[i]].second;
        }
    }
};