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
int mem[5][100];

vi coin_value = {1, 3, 4, 5};
int coin_change(int id, int val, int ans)
{

    if (val == 0)
        return ans;
    if (val < 0)
        return INF;
    if (mem[id][val] != -1)
        return mem[id][val];
    //if (val >= coin_value[id])
    return mem[id][val] = min(coin_change(id, val - coin_value[id], ans + 1), coin_change(id - 1, val, ans));
}
int main()
{
    memset(mem, -1, sizeof(mem));
    int val = 7;
    cout << coin_change(3, val, 0) << endl;
    // for (int i = 0; i < 100; i++)
    //     cout << mem[i] << " ";
    return 0;
}