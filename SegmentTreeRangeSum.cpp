#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    vector<int> tree, lazy;
    int n;

    void build(vector<int> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    void RangeUpdatePerform(int node, int start, int end, int l, int r, int val)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > r || end < l)
        {
            return;
        }

        if (start >= l && end <= r)
        {
            tree[node] += (end - start + 1) * val;
            if (start != end)
            {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        RangeUpdatePerform(2 * node, start, mid, l, r, val);
        RangeUpdatePerform(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int queryRangePerform(int node, int start, int end, int l, int r)
    {
        if (lazy[node] != 0)
        {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end)
            {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > r || end < l)
            return 0;

        if (start >= l && end <= r)
        {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = queryRangePerform(2 * node, start, mid, l, r);
        int right = queryRangePerform(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

public:
    SegmentTree(vector<int> arr)
    {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    void RangeUpdate(int l, int r, int val)
    {
        RangeUpdatePerform(1, 0, n - 1, l, r, val);
    }
    int queryRange(int l, int r)
    {
        return queryRangePerform(1, 0, n - 1, l, r);
    }
};
