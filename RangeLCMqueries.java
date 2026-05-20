/*Range LCM Queries

Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:

Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the subarray from index L to R (inclusive).
Process all queries sequentially and return a list containing the results of all Type 2 queries.

Note: All operations follow 0-based indexing.

Examples :

Input: arr[] = [2, 3, 4, 6, 8, 16], queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
Output: [12, 16]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 2]: LCM of [2, 3, 4] = 12
[1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
[2, 2, 5]: LCM of [4, 8, 8, 16] = 16
Input: arr[] = [1, 2, 3, 4],  queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
Output: [12, 10]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 3]: LCM of [1, 2, 3, 4] = 12
[1, 0, 5]: array becomes [5, 2, 3, 4]
[2, 0, 1]: LCM of [5, 2] = 10
Constraints:
1 ≤ arr.size() ≤ 104
1 ≤ queries.size() ≤ 105
0 ≤ L ≤ R ≤ arr.size() - 1
0 ≤ index ≤ arr.size() - 1
1 ≤ arr[i], value ≤ 104 */

import java.util.*;

class SegmentTree {
    private int[] tree;
    private int[] arr;
    int n;

    int findGCD(int a, int b) {
        if (b == 0)
            return a;
        return findGCD(b, a % b);
    }

    int findLCM(int a, int b) {
        return ((a * b) / (findGCD(a, b)));
    }

    public SegmentTree(int[] input) {
        arr = input.clone();
        n = arr.length;
        tree = new int[4 * n + 4];
        build(1, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = findLCM(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = findLCM(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int left, int right) {
        if (left > end || right < start) {
            return 1;
        }
        if (left <= start && right >= end) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int lefty = query(2 * node, start, mid, left, right);
        int righty = query(2 * node + 1, mid + 1, end, left, right);
        return findLCM(lefty, righty);
    }
}

public class RangeLCMqueries {
    public ArrayList<Long> RangeLCMQuery(int[] arr, int[][] queries) {
        // code here
        SegmentTree st = new SegmentTree(arr);
        ArrayList<Long> ans = new ArrayList<Long>();
        int n = arr.length;
        for (int[] query : queries) {
            if (query[0] == 1) {
                st.update(1, 0, n - 1, query[1], query[2]);
            } else if (query[0] == 2) {
                int temp = st.query(1, 0, n - 1, query[1], query[2]);
                ans.add((long) temp);
            }
        }
        return ans;
    }
}
