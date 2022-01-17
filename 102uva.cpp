#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

int main()
{

    int A[9];
    unordered_map<char, vector<int>> pos;
    pos['B'] = vector<int>({0, 3, 6});
    pos['G'] = vector<int>({1, 4, 7});
    pos['C'] = vector<int>({2, 5, 8});
    while (scanf("%d %d %d %d %d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4], &A[5], &A[6], &A[7], &A[8]) != EOF)
    {
        string s = "BCG";
        int ans = INT_MAX;
        string ans_str;
        do
        {
            int sum = 0;
            for (int i = 0; i < s.length(); i++)
            {
                char c = s[i];
                for (int j = 0; j < 3; j++)
                {
                    
                    if (j != i)
                    {
                        //cout << A[pos[c][j]];
                        sum += A[pos[c][j]];
                    }
                }
            }
            if (sum < ans)
            {
                ans = sum;
                ans_str = s;
            }

        } while (next_permutation(s.begin(), s.end()));
        cout << ans_str << " " << ans << endl;
    }
    return 0;
}