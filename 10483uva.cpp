#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap<double,string> pf;
    double A, B;
    cin >> A >> B;
    int X = A * 100.0, Y = B * 100.0;

    for (int i = 1; 3 * i <= Y; i++)
    {
        for (int j = i; 2 * j <= Y - i; j++)
        {
            int W = i + j;
            int V = i * j;

            if (V <= 10000)
                continue;
            if ((W * 10000) % (V - 10000) != 0)
                continue;
            
            int k = (W * 10000) / (V - 10000);
W+=k;
            if (k >= j && i + j + k <= Y && i + j + k >= X)
              {  
                  char arr[100];
                sprintf(arr,"%d.%02d = %d.%02d + %d.%02d + %d.%02d = %d.%02d * %d.%02d * %d.%02d\n",W/100,W%100, i / 100, i % 100, j / 100, j % 100, k / 100, k % 100, i / 100, i % 100, j / 100, j % 100, k / 100, k % 100);
                string ans(arr);
                pf.insert({W,ans});
              }
        }
    }
    for(auto op : pf)
        cout<<op.second;
    return 0;
}
