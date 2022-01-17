#include <bits/stdc++.h>
using namespace std;
int ans[311][2];
int main()
{

    vector<int> ranges;
    for (int i = 0; i <= 20; i++)
    {
        ranges.push_back(i);
        ranges.push_back(2 * i);
        ranges.push_back(3 * i);
    }
    ranges.push_back(50);
    int n;
    cin >> n;
    while (n > 0)
    {
        int per = 0;
        int comb = 0;
        unordered_set<string> seen;
        for (int i : ranges)
        {
            for (int j : ranges)
            {
                for (int k : ranges)
                {
                    if (i + j + k == n)
                    {

                        string s1 = to_string(i) + " " + to_string(j) + " " + to_string(k);
                        if (seen.find(s1) == seen.end()) //not found
                        {
                            comb++;
                            if (i != j && j != k && i != k)
                            {
                                per += 6;
                            }
                            else if (i == j && j == k)
                            {
                                per++;
                            }
                            else
                            {
                                per += 3;
                            }

                            string s2 = to_string(i) + " " + to_string(k) + " " + to_string(j);
                            string s3 = to_string(j) + " " + to_string(i) + " " + to_string(k);
                            string s4 = to_string(j) + " " + to_string(k) + " " + to_string(i);
                            string s5 = to_string(k) + " " + to_string(j) + " " + to_string(i);
                            string s6 = to_string(k) + " " + to_string(i) + " " + to_string(j);

                            seen.insert(s1);
                            seen.insert(s2);
                            seen.insert(s2);
                            seen.insert(s3);
                            seen.insert(s4);
                            seen.insert(s5);
                            seen.insert(s6);
                        }
                    }
                }
            }
        }

        if (comb)
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << per << "." << endl;
        }
        else
        {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        for (int i = 0; i < 70; ++i)
            cout << "*";
        cout << endl;

        cin >> n;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}
