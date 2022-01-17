#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

class SegmentTree
{
private:
    struct Node
    {
        int val;
        int start;
        int end;
        int update;

        Node()
        {
            val = 0;
            start = 0;
            end = 0;
            update = 0;
        }
    };

    vector<int> A, input, start;
    vector<Node> st;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void init(int p, int L, int R)
    {
        st[p].start = L;
        st[p].end = R;
        st[p].update = 0;
        if (L == R)
        {

            st[p].val = A[L];

            return;
        }
        int mid = (L + R) / 2;
        init(left(p), L, mid);
        init(right(p), mid + 1, R);
        update(p);
    }

    int query(int p, int L, int R)
    {

        if (R < st[p].start || st[p].end < L)
            return INT_MIN; //for range min query

        else if (L <= st[p].start && st[p].end <= R) //node is completly in range
        {
            return st[p].val;
        }
        else //range is partialy inside node
        {
            //prop(p);

            int max_left = query(left(p), L, R);
            int max_right = query(right(p), L, R);

            //update(p);

            return max(max_left, max_right);
        }
    }

    void prop(int p)
    {
        if (st[p].update == 0) //if there is no update you can delete this if u want
        {
            return;
        }
        else
        {
            st[left(p)].update += st[p].update;
            st[right(p)].update += st[p].update;
            st[p].update = 0;
        }
    }

    void update(int p)
    {

        // your operation can change insted of min
        st[p].val = max(st[left(p)].val, st[right(p)].val);
    }

public:
    SegmentTree(vector<int> &Aa, vector<int> &in, vector<int> &str)
    {
        input = in;
        start = str;
        A = Aa;
        this->n = (int)A.size();
        st.resize(4 * n + 1);
        init(1, 0, n - 1);
    }

    int query(int L, int R)
    {
        return query(1, L, R);
    }
};
int main()
{
    int n, q;

    while (scanf("%d", &n) && n != 0)
    {
        cin >> q;
        vector<int> input(n, 0), cnt(n, 0), start(n, 0);
        map<int, int> cc;
        // input.resize(n,0);
        // cnt.resize(n,0);
        // start.resize(n,0);

        for (int i = 0; i < n; i++)
        {
            int ww;
            cin >> ww;
            input[i] = ww;
            if (cc.find(input[i]) != cc.end())
            {
                cc[input[i]]++;
                start[i] = start[i - 1];
            }
            else
            {
                cc[input[i]] = 1;
                start[i] = i;
            }
        }
        for (int i = 0; i < n; i++)
            cnt[i] = cc[input[i]];

        SegmentTree segtree(cnt, input, start);
        for (int i = 0; i < q; i++)
        {
            int L, R;
            cin >> L >> R;
            L--;
            R--;
            //case 1 :
            if (input[L] == input[R])
                cout << (R - L + 1) << endl; //This will change
            //case 2:
            else
            {
                int cnt1 = cnt[L] - (L - start[L]);
                int x = L + cnt1;
                int cnt2 = (R - start[R] + 1);
                int y = start[R] - 1;

                cout << max(segtree.query(x, y), max(cnt1, cnt2)) << endl;
            }
        }
    }
    return 1;
}