#include <bits/stdc++.h>
using namespace std;
int pos[8];
int path[] int board[8][8];
vector<vector<int>> sol;

// bool check(int r, int c)
// {
//     //row
//     for (int i = 0; i < 8; i++)
//         if (board[r][i])
//             return false;
//     //check diagoanl
//     int tr = r, tc = c;
//     while (tr < 8 && tc < 8)
//     {
//         if (board[tr][tc])
//             return false;
//         tr++;
//         tc++;
//     }
//     tr = r;
//     tc = c;
//     while (tr >= 0 && tc >= 0)
//     {
//         if (board[tr][tc])
//             return false;
//         tr--;
//         tc--;
//     }
//     tr = r;
//     tc = c;
//     while (tr >= 0 && tc < 8)
//     {
//         if (board[tr][tc])
//             return false;
//         tr--;
//         tc++;
//     }
//     tr = r;
//     tc = c;
//     while (tc >= 0 && tr < 8)
//     {
//         if (board[tr][tc])
//             return false;
//         tr++;
//         tc--;
//     }

//     return true;
// }
// void solve(int q, vector<int> a)
// {
//     if (q >= 8)
//     {
//         //savve answer
//         sol.push_back(a);
//     }
//     for (int i = 0; i < 8; i++)
//     {
//         if (check(i, q))
//         {
//             board[i][q] = 1;
//             a.push_back(i);
//             solve(q + 1, a);
//             a.erase(a.begin() + q);
//             board[i][q] = 0;
//         }
//     }
// }
// int main()
// {
//     vector<int> a;
//     solve(0, a);
//     int case_id = 1;
//     int n;
//     while (cin >> n)
//     {

//         int tot = INT_MAX;
//         pos[0] = --n;
//         for (int i = 1; i < 8; i++)
//         {
//             cin >> pos[i];
//             pos[i]--;
//         }

//         for (int i = 0; i < sol.size(); i++)
//         {
//             int sum = 0;
//             for (int j = 0; j < 8; j++)
//             {
//                 sum += abs(pos[j] - sol[i][j]) == 0 ? 0 : 1;
//             }
//             // cout << sum << endl;
//             tot = min(sum, tot);
//         }
//         cout << "Case " << case_id++ << ": " << tot << endl;
//     }
//     return 0;
// }

bool check(int r, int c)
{
    //row
    for (int i = 0; i < c; i++)
        if (i != c && path[i] == r)
            return false;

    for (int i = 0; i < c; i++)
    {
        if (i != c && abs(path[i] - r) == abs(c - i))
            return false;
    }
    return true;
}

void()

    int main()
{
    vector<int> a;
    solve(0, a);
    int case_id = 1;
    int n;
    while (cin >> n)
    {

        int tot = 0;
        pos[0] = n;
        for (int i = 1; i < 8; i++)
            cin >> pos[i];

        for (int i = 0; i < sol.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < 8; j++)
            {
                sum += abs(pos[j] - sol[i][j]);
            }
            tot = max(sum, tot);
        }
        cout << "Case " << case_id++ << ": " << tot << endl;
    }
    return 0;
}