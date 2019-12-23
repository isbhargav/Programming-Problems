#include <bits/stdc++.h>
using namespace std;
vector<int> times(1000);
// int sol(int n, int p)
// {
//     if (n == 1)
//     {
//         if (p == 1)
//             cout << times[0] << endl;
//         return times[0];
//     }
//     else if (n == 2)
//     {
//         if (p == 1)
//             cout << times[0] << " " << times[1] << endl;
//         return times[1];
//     }
//     else if (n == 3)
//     {
//         if (p == 1)
//             cout << times[0] << " " << times[1] << "\n"
//                  << times[0] << "\n"
//                  << times[0] << " " << times[2] << endl;
//         return times[0] + times[1] + times[2];
//     }
//     else
//     {
//         int end = n - 2;
//         int start = 1;
//         while (end - 2 > start + 1)
//         {
//             end -= 2;
//             start++;
//         }
//         int cost1 = 0;
//         for (int i = 1; i < end; i++)
//         {
//             cost1 += times[i] + times[0];
//             if (p == 1)
//                 cout << times[0] << " " << times[i] << "\n"
//                      << times[0] << endl;
//         }
//         int cost2 = 0;
//         int j = 1;
//         for (int i = n - 1; i > end && j < i; i--, j++)
//         {
//             cost2 += times[i] + times[j];
//             if (p == 1)
//                 cout << times[i - 1] << " " << times[i] << "\n"
//                      << times[j] << endl;
//         }
//         return cost1 + cost2 + sol(j, p);
//     }
// }
int sol(int n, int p)
{
    if (n < 4)
    {
        if (n == 1)
        {
            if (p == 1)
                cout << times[0] << endl;
            return times[0];
        }
        else if (n == 2)
        {
            if (p == 1)
                cout << times[0] << " " << times[1] << endl;
            return times[1];
        }
        else if (n == 3)
        {
            //if(times[0] + times[1] + times[2] < times[2] + times[1] + times[1])
            if (p == 1)
                cout << times[0] << " " << times[1] << "\n"
                     << times[0] << "\n"
                     << times[0] << " " << times[2] << endl;
            return times[0] + times[1] + times[2];
        }
    }
    else
    {
        if (times[0] + times[n - 2] < 2 * times[1])
        {
            // smallest will take every one
            if (p == 1)
                cout
                    << times[0] << " " << times[n - 2] << "\n"
                    << times[0] << "\n"
                    << times[0] << " " << times[n - 1] << "\n"
                    << times[0] << endl;

            return times[n - 1] + times[n - 2] + 2 * times[0] + sol(n - 2, p);
        }
        else
        {
            //first two will do round trip
            if (p == 1)
                cout
                    << times[0] << " " << times[1] << "\n"
                    << times[0] << "\n"
                    << times[n - 2] << " " << times[n - 1] << "\n"
                    << times[1] << endl;

            return 2 * times[1] + times[n - 1] + times[0] + sol(n - 2, p);
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> times[i];
        }
        sort(times.begin(), times.begin() + n);
        cout << sol(n, 0) << endl;
        sol(n, 1);
        if (t)
            cout << endl;
    }
    return 0;
}
