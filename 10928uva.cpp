/******************** Beginning of Template **************************/
/************ ALL HEADER FILE ***********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>

/************************************ ALL DEFINE ****************************************************/
#define FORS(i, j, k, step) for (int i = j; i < k; i += step)
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define RFORS(i, j, k, step) for (int i = j; i >= k; i -= step)
#define RFOR(i, j, k, step) for (int i = j; i >= k; i--)
#define REP(i, k) for (int i = (0); i < (k); i++)
#define RREP(i, k) for (int i = j; i >= (k); i--)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.begin(), cont.end()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define mp make_pair
#define pb push_back
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF (int)INT_MAX
#define EPS (int)1e-9
#define PI acos(-1)
#define MOD 1000000007
#define MIN(A, B) A < B ? A : B

using namespace std;

/************************************ END OF DEFINE ****************************************************/

/************************************ ALL TYPEDEF ****************************************************/
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef long long int32;
typedef unsigned long long uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

template <class T>
T sqr(T val)
{
    return val * val;
}

/************************************ ALL DEFINE ****************************************************/

/************************************ END OF PREHEADER ***********************************************/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int min_val = INF;
        int n;
        cin >> n;
        //clear buffer
        getchar();
        n++;
        vi graph(n, 0);
        FOR(i, 1, n)
        {
            string s;
            int x = 1;
            getline(cin, s);
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == ' ')
                    x++;
            }

            graph[i] = x;

            min_val = MIN(min_val, graph[i]);
        }
        vi ans;
        FOR(i, 1, n)
        {

            if (graph[i] == min_val)
                ans.push_back(i);
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << (i != ans.size() - 1 ? " " : "\n");
        }
    }
    return 0;
}