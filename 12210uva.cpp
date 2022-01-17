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
        // if #Bach >= #Spin -> all of them get married for sure
        if (b <= s)
            cout << 0 << endl;
        else// b-s will reamin unmarried and the youngest on will for sure be un married
            cout << b - s << " " << bach[0] << endl;
    }
    return 0;
}
