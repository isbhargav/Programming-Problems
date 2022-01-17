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
int parent[800], rank[800];
void make_set(int n)
{
    parent[n] = n;
    rank[n] = 0;
}
int find(int n)
{
    if (parent[n] == n)
        return n;
    return find(parent[n]);
}

void union(int a, int b)
{
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b)
        return;

    if (rank[p_a] > rank[p_b])
    {
        parent[p_b] = p_a;
        return;
    }
    else if (rank[p_a] < rank[p_b])
    {
         parent[p_a] = p_b;
        return;
    }
    else
    {
        parent[p_b] = p_a;
        rank[p_b]++;
        return 
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 1; i < n + 1; i++)
        {
            make_set(i)
        }
        char c;
        int a, b,c1=0,c2=0;
        while (scanf("%c %d %d", &c, &a, &b))
        {
            if (c == 'c')
            {
                union(a,b);
            }
            else if(c=='q')
            {
                if(find(a)==find(b))
                c1++;
                else
                c2++;
            }
        }
    }
    return 0;
}