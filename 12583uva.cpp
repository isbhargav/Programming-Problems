#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int caseid = 1;
  while (t--)
  {
    int n;
    cin >> n;
    int qn;
    cin >> qn;
    char a[qn];

    string s;
    cin >> s;
    int ans = 0;
    int end = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (i < qn)
      {
        char name = s[i];

        //search for name in arr
        for (int j = 0; j < end; j++)
        {
          if (a[j] == name)
          {
            ans++;
            break;
          }
        }

        a[end] = name;
        end++;
        end = end % qn;
      }
      else
      {
        char name = s[i];

        //search for name in arr
        for (int j = 0; j < qn; j++)
        {

          if (a[j] == name)
          {
            ans++;
            break;
          }
        }

        a[end] = name;
        end++;
        end = end % qn;
      }
    }
    cout << "Case " << caseid++ << ": " << ans << endl;
  }
  return 0;
}