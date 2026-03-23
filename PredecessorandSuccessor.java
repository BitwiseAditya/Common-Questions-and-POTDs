/*Predecessor and Successor

You are given the root of a BST and an integer key. 
You need to find the inorder predecessor and successor
 of the given key. If either predecessor or successor 
 is not found, then set it to NULL.

Note: In an inorder traversal the number just smaller than the
 target is the predecessor and the number just greater than the
target is the successor.  */

import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class PredecessorandSuccessor {
    Node pred;
    Node succ;

    public void findPredecessor(Node root, int key) {
        if (root == null)
            return;
        if (root.data < key) {
            pred = root;
            findPredecessor(root.right, key);
        } else {
            findPredecessor(root.left, key);
        }
    }

    public void findSuccessor(Node root, int key) {
        if (root == null)
            return;
        if (root.data > key) {
            succ = root;
            findSuccessor(root.left, key);
        } else {
            findSuccessor(root.right, key);
        }
    }

    public ArrayList<Node> findPreSuc(Node root, int key) {
        // code here
        ArrayList<Node> ans = new ArrayList<>();
        pred = null;
        succ = null;
        findPredecessor(root, key);
        findSuccessor(root, key);
        ans.add(pred);
        ans.add(succ);
        return ans;
    }
}
