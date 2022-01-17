/******************** Beginning of Template **************************/
/************ ALL HEADER FILE ***********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
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

#define FORS(i, j, k, step) for (int i = j; i < k; i += step)
#define FOR(i, j, k) for (int i = j; i < k; i++)
#define RFORS(i, j, k, step) for (int i = j; i >= k; i -= step)
#define RFOR(i, j, k, step) for (int i = j; i >= k; i--)
#define REP(i, k) for (int i = (0); i < (k); i++)
#define RREP(i, k) for (int i = j; i >= (k); i--)
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.begin(), cont.end()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define mp make_pair
#define pb push_back
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF (int)INT_MAX
#define EPS (int)1e-9
#define PI acos(-1)
#define MOD 1000000007
using namespace std;

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
T sqr(T val) { return val * val; }

int A[8] = {-7, 10, 9, 2, 3, 8, 8, 1};
vi ans;

void comp_search(int i, vi &t, int n)
{
    if (n >= 8)
    {
        if (ans.size() < t.size())
        {
            ans.clear();
            for (int i = 0; i < t.size(); i++)
                ans.push_back(t.at(i));
        }
        return;
    }

    if (i == 0)
    {
        //we can have both cases
        vi a(t);
        vi b(t);

        b.push_back(A[n]);
        comp_search(i, a, n + 1);
        comp_search(i + 1, b, n + 1);
    }
    else
    {
        if (t.at(i - 1) < A[n])
        {
            //we can have both cases
            vi a(t);
            vi b(t);

            b.push_back(A[n]);
            comp_search(i, a, n + 1);
            comp_search(i + 1, b, n + 1);
        }
        else
        {
            comp_search(i, t, n + 1);
        }
    }
};

int main()
{
    vi t; // = new vi();
    comp_search(0, t, 0);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}