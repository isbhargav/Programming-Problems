#include <bits/stdc++.h>
using namespace std;
int main()
{
    int b, s, cid = 1;
    while (cin >> b >> s && (b && s))
    {
        cout << "Case " << cid++ << ": ";
        vector<int> bach(b);
        vector<int> spin(s);

        for (int i = 0; i < b; i++)
        {
            cin >> bach[i];
        }

        for (int i = 0; i < s; i++)
        {
            cin >> spin[i];
        }
        sort(bach.begin(), bach.end());
        if (b <= s)
            cout << 0 << endl;
        else
            cout << b - s << " " << bach[0] << endl;
    }
    return 0;
}