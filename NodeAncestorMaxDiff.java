/*Node and Ancestor Max Diff

Given the root of a binary tree, find the maximum difference between an ancestor 
node A and its descendant node B, i.e., maximize A - B.

Examples :

Input: root[] = [5, 2, 1] 

Output: 4
Explanation: The maximum difference we can get is 4, which is between 5 and 1.
Input: root[] = [1, 2, 3, N, N, N, 7] 

Output: -1
Explanation: The maximum difference we can get is -1, which is between 1 and 2.
Constraints:

2 ≤ size of binary tree ≤ 104
0 ≤ node.data ≤ 105
2 ≤ Number of edges ≤ 104 */

//Structure of binary tree node

class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class NodeAncestorMaxDiff {
    int postOrderTraversalMinFinding(Node root, int[] ans) {
        if (root == null)
            return Integer.MAX_VALUE;

        int leftMin = postOrderTraversalMinFinding(root.left, ans);
        int rightMin = postOrderTraversalMinFinding(root.right, ans);

        ans[0] = Math.max(ans[0], root.data - Math.min(leftMin, rightMin));

        return Math.min(root.data, Math.min(leftMin, rightMin));
    }

    int maxDiff(Node root) {
        // code here
        int[] ans = new int[1];
        ans[0] = Integer.MIN_VALUE;
        int temp = postOrderTraversalMinFinding(root, ans);
        return ans[0];
    }
}
