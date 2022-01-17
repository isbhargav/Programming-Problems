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

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        int c[i + 1];
        for (int k = 0; k <= i; k++)
            cin >> c[k];

        int d;
        cin >> d;

        int k;
        cin >> k;
        int sum = 0;
        for (int m = 1;; m++)
        {

            if (k <= ((m * (m + 1)) / 2) * d)
            {
                int64 an = c[0];
                for (int w = 1; w <= i; w++)
                    an += (c[w] * (int64)pow(m, w));

                cout << an << endl;
                break;
            }
        }
    }

    return 0;
}