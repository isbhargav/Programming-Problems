#include <bits/stdc++.h>
using namespace std;

int cap, last, num_ord;
int max_sum = 0;
struct Order
{
    int start;
    int end;
    int num_pass;
    int earing()
    {
        return (end - start) * num_pass;
    }
};
Order orders[30];
void dfs(int id, int sum, int pass, vector<int> path)
{

    if (id >= num_ord)
    {
        max_sum = max(sum, max_sum);
        return;
    }

    //not take this order
    dfs(id + 1, sum, pass, path);
    //taking this order
    //remove  passangers leaving
    vector<int> new_path;
    for (auto &x : path)
    {
        if (orders[x].end <= orders[id].start)
        {
            pass -= orders[x].num_pass;
            x = 29;
        }
        // else
        // {
        //     new_path.push_back(x);
        // }
    }
    int n_pass = orders[id].num_pass + pass;
    if (n_pass <= cap)
    {
        path.push_back(id);
        dfs(id + 1, sum + orders[id].earing(), n_pass, path);
    }
}

int main()
{
    while (cin >> cap >> last >> num_ord && (cap || last || num_ord))
    {
        max_sum = 0;
        for (int i = 0; i < num_ord; i++)
            cin >> orders[i].start >> orders[i].end >> orders[i].num_pass;
        vector<int> a;
        sort(orders, orders + num_ord, [](Order &a, Order &b) { return a.start < b.start; });
        dfs(0, 0, 0, a);
        cout << max_sum << endl;
    }
}