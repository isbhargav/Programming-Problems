#include <bits/stdc++.h>
using namespace std;

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
            update = -2;
        }
    };

    vector<int> A;
    vector<Node> st;
    int n;
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }

    void init(int p, int L, int R)
    {
        st[p].start = L;
        st[p].end = R;
        st[p].update = -2;

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

    void range_update(int p, int L, int R, int val)
    {
        if (R < st[p].start || st[p].end < L)
            return;
        else if (L <= st[p].start && st[p].end <= R) //node is completly in range
        {
            if(st[p].update==-2)
                st[p].update = val; //This will change
            else if((st[p].update==1 || st[p].update==0 )&& (val==1 || val==0))
                st[p].update=val;
            else if((st[p].update==1 || st[p].update==0 )&& (val==-1))
                st[p].update=st[p].update==0?1:0;
            else if((st[p].update==-1)&& (val==-1))
                st[p].update=-2;
        }
        else //range is partialy inside node
        {
            prop(p);

            range_update(left(p), L, R, val);
            range_update(right(p), L, R, val);

            update(p);
        }
    }

    int query(int p, int L, int R)
    {

        if (R < st[p].start || st[p].end < L)
            return 0;                                //for range min query
        else if (L <= st[p].start && st[p].end <= R) //node is completly in range
        {
            if (st[p].update == -2)
                return st[p].val; //This will change
            if (st[p].update == 0 || st[p].update == 1)
                return  (st[p].end - st[p].start + 1) * st[p].update;
            if (st[p].update == -1)
                return (st[p].end - st[p].start + 1) - st[p].val;
        }
        //range is partialy inside node

        prop(p);

        int res_left = query(left(p), L, R);
        int res_right = query(right(p), L, R);

        update(p);

        return (res_left + res_right);
    }

    void prop(int p)
    {
        if (st[p].update == -2) //if there is no update you can delete this if u want
        {
            return;
        }
        else
        {

            if (st[p].update == 0 || st[p].update == 1)
            {
                st[left(p)].update = st[p].update;
                st[right(p)].update = st[p].update;
            }
            else if (st[p].update == -1)
            {
                if (st[left(p)].update == 0)
                    st[left(p)].update = 1;
                else if (st[left(p)].update == 1)
                    st[left(p)].update = 0;
                else if (st[left(p)].update == -1)
                    st[left(p)].update = -2;

                if (st[right(p)].update == 0)
                    st[right(p)].update = 1;
                else if (st[right(p)].update == 1)
                    st[right(p)].update = 0;
                else if (st[right(p)].update == -1)
                    st[right(p)].update = -2;
            }

            st[p].update = -2;
        }
    }

    void update(int p)
    {

        // your operation can change insted of min
        int res_left, res_right;
        if (st[left(p)].update == -2)
            res_left = st[left(p)].val; //This will change
        else if (st[left(p)].update == 0 || st[left(p)].update == 1)
            res_left = (st[left(p)].end - st[left(p)].start + 1) * st[left(p)].update;
        else if (st[left(p)].update == -1)
            res_left = (st[left(p)].end - st[left(p)].start + 1) - st[left(p)].val;

        if (st[right(p)].update == -2)
            res_right = st[right(p)].val; //This will change
        else if (st[right(p)].update == 0 || st[right(p)].update == 1)
            res_right = (st[right(p)].end - st[right(p)].start + 1) * st[right(p)].update;
        else if (st[right(p)].update == -1)
            res_right = (st[right(p)].end - st[right(p)].start + 1) - st[right(p)].val;

        st[p].val = res_left + res_right;
    }

public:
    SegmentTree(vector<int> &Aa)
    {
        A = Aa;
        this->n = (int)A.size();
        st.resize(4 * n + 1);
        init(1, 0, n - 1);
    }

    void range_update(int L, int R, int val)
    {
        range_update(1, L, R, val);
    }

    int query(int L, int R)
    {
        return query(1, L, R);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        string total_string = "";
        for (int i = 0; i < m; i++)
        {
            int n;
            cin >> n;
            string s, pt = "";
            cin >> s;
            while (n--)
            {
                pt += s;
            }

            total_string += pt;
        }
        vector<int> A(total_string.length(), 0);
        for (int i = 0; i < total_string.length(); i++)
            A[i] = total_string[i] == '1' ? 1 : 0;
        SegmentTree segtree(A);
        int q;
        cin >> q;
        while (q--)
        {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'F')
                segtree.range_update(a, b, 1);
            else if (c == 'E')
                segtree.range_update(a, b, 0);
            else if (c == 'I')
                segtree.range_update(a, b, -1);
            else if (c == 'S')
                cout << segtree.query(a, b) << endl;
        }
    }
    return 0;
}