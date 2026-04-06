/*
 * Huffman Encoding
 * 
 * Given a string s of distinct characters and their corresponding frequency f[
 * ] i.e. character s[i] has f[i] frequency. You need to build the Huffman tree
 * and return all the huffman codes in preorder traversal of the tree.
 * Note: While merging if two nodes have the same value, then the node which
 * occurs at first will be taken on the left of Binary Tree and the other one to
 * the right, otherwise Node with less value will be taken on the left of the
 * subtree and other one to the right.
 * 
 * Examples:
 * 
 * Input: s = "abcdef", f[] = {5, 9, 12, 13, 16, 45}
 * Output: [0, 100, 101, 1100, 1101, 111]
 * Explanation:
 * 
 * HuffmanCodes will be:
 * f : 0
 * c : 100
 * d : 101
 * a : 1100
 * b : 1101
 * e : 111
 * Constraints:
 * 1 ≤ s.size() = f.size() ≤ 26
 */

import java.util.*;
import java.lang.Math;

class Node {
    char character;
    int frequency;
    int id;
    Node left;
    Node right;

    public Node(char character, int frequency, int id, Node left, Node right) {
        this.character = character;
        this.frequency = frequency;
        this.left = left;
        this.right = right;
        this.id = id;
    }

    public Node(Node left, Node right) {
        character = '\0';
        this.frequency = left.frequency + right.frequency;
        this.left = left;
        this.right = right;
        this.id = Math.min(left.id, right.id);
    }
}

class HuffmanEncoding {
    public void preorder(Node root, String code, ArrayList<String> ans) {
        if (root == null)
            return;
        if (root.left == null && root.right == null) {
            if (code.equals("")) {
                code = "0";
            }
            ans.add(code);
            return;
        }
        preorder(root.left, code + '0', ans);
        preorder(root.right, code + '1', ans);
    }

    public ArrayList<String> huffmanCodes(String s, int f[]) {
        // Code here
        Comparator<Node> com = new Comparator<Node>() {
            public int compare(Node none, Node ntwo) {
                if (none.frequency != ntwo.frequency) {
                    return Integer.compare(none.frequency, ntwo.frequency);
                } else {
                    return Integer.compare(none.id, ntwo.id);
                }
            }
        };
        PriorityQueue<Node> pq = new PriorityQueue<Node>(com);
        int n = s.length();
        int idCounter = 0;
        for (int i = 0; i < n; i++) {
            Node temp = new Node(s.charAt(i), f[i], idCounter++, null, null);
            pq.offer(temp);
        }
        while (pq.size() != 1) {
            Node n1 = pq.poll();
            Node n2 = pq.poll();
            if (n1.frequency > n2.frequency) {
                Node temp = new Node(n2, n1);
                pq.offer(temp);
            } else if (n1.frequency == n2.frequency) {
                if (n1.id < n2.id) {
                    Node temp = new Node(n1, n2);
                    pq.offer(temp);
                } else {
                    Node temp = new Node(n2, n1);
                    pq.offer(temp);
                }
            } else {
                Node temp = new Node(n1, n2);
                pq.offer(temp);
            }
        }
        ArrayList<String> ans = new ArrayList<String>();
        Node root = pq.poll();
        preorder(root, "", ans);
        return ans;
    }
}
