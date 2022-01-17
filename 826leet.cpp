#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> my_min_heap;
    for (int i = 0; i < difficulty.size(); i++)
    {

        my_min_heap.push({difficulty[i], profit[i]});
    }
    sort(worker.begin(), worker.end());
    int best = 0, sum = 0;
    for (int w : worker)
    {

        while (!my_min_heap.empty() && w >= (my_min_heap.top()).first)
        {
            pair<int, int> tp = my_min_heap.top();
            my_min_heap.pop();
            best = max(best, tp.second);
        }

        sum += best;
    }
    return sum;
}
int main()
{

    vector<int> difficulty = {27, 28, 31, 44, 44};
    vector<int> profit = {29, 39, 60, 84, 93};
    vector<int> worker = {67, 53, 61, 56, 63};
    cout << maxProfitAssignment(difficulty, profit, worker);
    return 0;
}