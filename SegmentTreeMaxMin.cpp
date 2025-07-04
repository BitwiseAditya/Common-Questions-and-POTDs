#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void rangeUpdate(int node, int start, int end, int left, int right, int val)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > right || end < left)
            return;
        if (start >= left && end <= right)
        {
            tree[node] += val;
            if (start != end)
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        rangeUpdate(2 * node, start, mid, left, right, val);
        rangeUpdate(2 * node + 1, mid + 1, end, left, right, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    int queryRange(int node, int start, int end, int left, int right)
    {
        if (lazy[node] != 0)
        {
            tree[node] += lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (start > right || end < left)
            return INT_MAX;
        if (start >= left && end <= right)
        {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int lefty = queryRange(2 * node, start, mid, left, right);
        int righty = queryRange(2 * node + 1, mid + 1, end, left, right);
        return min(lefty, righty);
    }
};
int main()
{
    int n, q;
    cin >> n; // Reading input from STDIN
    cin >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree st(arr);
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c == 'q')
        {
            int a, b;
            cin >> a;
            cin >> b;
            a--;
            b--;
            cout << st.queryRange(1, 0, n - 1, a, b) << endl;
        }
        else if (c == 'u')
        {
            int a, b, c;
            cin >> a;
            cin >> b;
            cin >> c;
            a--;
            b--;
            st.rangeUpdate(1, 0, n - 1, a, b, c);
        }
    }
    return 0;
}
