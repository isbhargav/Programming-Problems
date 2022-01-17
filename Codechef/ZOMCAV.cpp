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
            update = 0;
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

    void range_update(int p, int L, int R, int val)
    {
        if (R < st[p].start || st[p].end < L)
            return;
        else if (L <= st[p].start && st[p].end <= R) //node is completly in range
        {
            st[p].update += val; //This will change(keep in mind case of already haveing some update stored previously)
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
            return INT_MAX;                          //for range min query
        else if (L <= st[p].start && st[p].end <= R) //node is completly in range
        {
            return st[p].val += st[p].update; //This will change
        }
        else //range is partialy inside node
        {
            prop(p);

            int min_left = query(left(p), L, R);
            int min_right = query(right(p), L, R);

            update(p);

            return min(min_left, min_right);
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
        st[p].val = min(st[left(p)].val + st[left(p)].update, st[right(p)].val + st[right(p)].update);
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
        int n;
        cin >> n;
        vector<int> caves(n + 1, 0);
        SegmentTree seg(caves);
        bool flg=false;
        vector<int> H(n+1,0);
        unordered_map<int,int> dic;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            int l = (i-x)<1?1:(i-x);
            int r =  (i+x)>n?n:(i+x);
            seg.range_update(l,r,1);

        }
        for (int i = 1; i <= n; i++)
           {cin>>H[i];
           int w=seg.query(i,i);
             dic[w]++;  }

         for (int i = 1; i <= n; i++)
         {   
             if(dic.find(H[i])!=dic.end() && dic[H[i]]>0)
             {
                  dic[H[i]]--;
             }
             else
             {
                 cout<<"NO\n";
                 flg = true;
                 break;
             }
              
         }
         if(!flg)
            cout<<"YES\n";
         
        
         
        
    }
    return 0;
}