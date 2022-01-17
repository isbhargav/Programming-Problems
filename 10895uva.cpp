#include <bits/stdc++.h>
using namespace std;

void split()
{
    std::string s = "What is the right way to split a string into a vector of strings";
    std::stringstream ss(s);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        int t = m;
        vector<vector<pair<int, int>>> mat(m + 1, vector<pair<int, int>>()), matT(n + 1, vector<pair<int, int>>());
        for (int j = 1; j <= m; j++)
        {
            int a;
            scanf("%d", &a);
            int places[a];
            vector<pair<int, int>> cord;
            for (int i = 0; i < a; i++)
            {
                scanf("%d ", &places[i]);
            }
            for (int i = 0; i < a; i++)
            {
                int b;
                scanf("%d", &b);
                mat[j].push_back({places[i], b});
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                int p = mat[i][j].first;
                int r = mat[i][j].second;
                int z = i;
                matT[p].push_back({z, r});
            }
        }
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            //sort(matT[i].begin(),matT[i].end(),[](pair<int,int> &a,pair<int,int> &b){return a.first<b.first;});
            cout << matT[i].size();
            for (int j = 0; j < matT[i].size(); j++)
            {
                cout << " " << matT[i][j].first;
            }
            cout << endl;
            for (int j = 0; j < matT[i].size(); j++)
            {
                if (i == matT[i].size() - 1)
                    cout << matT[i][j].second;
                else
                    cout << matT[i][j].second << " ";
            }
            cout << endl;
        }
    }
    return 0;
}