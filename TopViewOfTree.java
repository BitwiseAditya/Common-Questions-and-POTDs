/*Top View of Binary Tree

You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

 */

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

class Pair<U, V> {
    U hd;
    V nd;

    Pair(U hd, V nd) {
        this.hd = hd;
        this.nd = nd;
    }
}

class Solution {
    public ArrayList<Integer> topView(Node root) {
        // code here
        TreeMap<Integer, Node> mp = new TreeMap<>();
        Queue<Pair<Integer, Node>> q = new LinkedList<>();
        q.offer(new Pair<Integer, Node>(0, root));
        while (!q.isEmpty()) {
            Queue<Pair<Integer, Node>> temp = new LinkedList<>();
            while (!q.isEmpty()) {
                Pair<Integer, Node> p = q.poll();
                if (!mp.containsKey(p.hd)) {
                    mp.put(p.hd, p.nd);
                }
                if (p.nd.left != null)
                    temp.offer(new Pair<Integer, Node>(p.hd - 1, p.nd.left));
                if (p.nd.right != null)
                    temp.offer(new Pair<Integer, Node>(p.hd + 1, p.nd.right));
            }
            q = temp;
            temp = null;
        }
        ArrayList<Integer> ans = new ArrayList<Integer>();
        for (Map.Entry<Integer, Node> e : mp.entrySet()) {
            ans.add(e.getValue().data);
        }
        return ans;
    }
}
