
/*
 * Vertical Tree Traversal
 
 * Given the root of a Binary Tree, find the vertical traversal of the tree
 * starting from the leftmost level to the rightmost level.
 * 
 * Note: If there are multiple nodes passing through a vertical line, then they
 * should be printed as they appear in level order traversal of the tree.
 * 
 * Examples:
 * 
 * Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, 8, N, 9, N, 10, 11, N]
 * 
 * Output: [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]
 * Explanation: The below image shows the horizontal distances used to print
 * vertical traversal starting from the leftmost level to the rightmost level.
 * 
 * Input: root = [1, 2, 3, 4, 5, N, 6]
 * 
 * Output: [[4], [2], [1, 5], [3], [6]]
 * Explanation: From left to right the vertical order will be [[4], [2], [1, 5],
 * [3], [6]]
 * Constraints:
 * 1 ≤ number of nodes ≤ 105
 * 1 ≤ node->data ≤ 105
 */
import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
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

class VerticalOrderTraversal {
    public ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // code here
        TreeMap<Integer, ArrayList<Integer>> mp = new TreeMap<>();
        Queue<Pair<Integer, Node>> q = new LinkedList<>();
        q.offer(new Pair<Integer, Node>(0, root));
        while (!q.isEmpty()) {
            Queue<Pair<Integer, Node>> temp = new LinkedList<>();
            while (!q.isEmpty()) {
                Pair<Integer, Node> p = q.poll();
                mp.computeIfAbsent(p.hd, key -> new ArrayList<Integer>()).add(p.nd.data);
                if (p.nd.left != null)
                    temp.offer(new Pair<Integer, Node>(p.hd - 1, p.nd.left));
                if (p.nd.right != null)
                    temp.offer(new Pair<Integer, Node>(p.hd + 1, p.nd.right));
            }
            q = temp;
            temp = null;
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (Map.Entry<Integer, ArrayList<Integer>> e : mp.entrySet()) {
            ans.add(e.getValue());
        }
        return ans;
    }
}
